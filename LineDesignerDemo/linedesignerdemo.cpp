#include "linedesignerdemo.h"
#include <qpoint.h>

LineDesignerDemo::LineDesignerDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	status = "Parameter console: \n";
	this->ui.textEdit->setText(status);
	f = 0;
	x0 = 0, y0 = 0;
	Width = 0, Length = 0;
	Height = 0;
	angle = 0;
	pi = 3.141593;
	l = 0, L = 0;
	x = 0, y = 0;
	start_x = 0, start_y = 0;

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(pushButton_Clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton_2_Clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton_3_Clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(pushButton_4_Clicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(pushButton_5_Clicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(pushButton_6_Clicked()));
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
	connect(ui.pushButton_output, SIGNAL(clicked()), this, SLOT(pushButton_output_Clicked()));
}

LineDesignerDemo::~LineDesignerDemo()
{

}
//输入内方位元素
void LineDesignerDemo::buttonClicked()
{
	QString f_str = this->ui.lineEdit_3->text();
	f = f_str.toDouble(&ok);
	QString x0_str = this->ui.lineEdit_5->text();
	x0 = x0_str.toDouble(&ok);
	QString y0_str = this->ui.lineEdit_6->text();
	y0 = y0_str.toDouble(&ok);
	status += "  Intrinsic parameters:\n";
	status = status + "  f =\t" + f_str + "cm\n";
	status = status + "  x0 =\t" + x0_str + "cm\n";
	status = status + "  y0 =\t" + y0_str + "cm\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//输入地区信息
void LineDesignerDemo::pushButton_3_Clicked()
{
	QString Width_str = this->ui.lineEdit_8->text();
	Width = Width_str.toDouble(&ok);
	QString Length_str = this->ui.lineEdit_7->text();
	Length = Length_str.toDouble(&ok);
	status += "  Area information:\n";
	status = status + "  Length =\t" + Length_str + "m\n";
	status = status + "  Width =\t" + Width_str + "m\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//计算航高
void LineDesignerDemo::pushButton_Clicked()
{
	QString ratio_str = this->ui.lineEdit->text();
	ratio = ratio_str.toDouble(&ok);
	Height = f*ratio*0.01;
	sprintf_s(buffer, "%f", Height);
	QString Height_str = buffer;
	status = status + "  Height =\t" + Height_str + "m\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
	this->ui.lineEdit_9->setText(Height_str);
}
//计算比例尺
void LineDesignerDemo::pushButton_4_Clicked()
{
	QString Height_str = this->ui.lineEdit_9->text();
	Height = Height_str.toDouble(&ok);
	ratio = 100 * Height / f;
	sprintf_s(buffer, "%f", ratio);
	QString ratio_str = buffer;
	status = status + "  Ratio =\t1: " + ratio_str + "\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
	this->ui.lineEdit->setText(ratio_str);
}
//输入像幅宽度，输出地幅宽度
void LineDesignerDemo::pushButton_2_Clicked()
{
	QString angle_str = this->ui.lineEdit_2->text();
	angle = angle_str.toDouble(&ok);
	L = angle * ratio / 100;
	sprintf_s(buffer, "%f", L);
	QString L_str = buffer;
	status = status + "  Image width:\t" + angle_str + "cm\n";
	status = status + "  Area width:\t" + L_str + "m\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//输入航向重叠度、胖向重叠度，计算航线
void LineDesignerDemo::pushButton_5_Clicked()
{
	QString x_str = this->ui.lineEdit_4->text();
	x = x_str.toDouble(&ok);
	QString y_str = this->ui.lineEdit_10->text();
	y = y_str.toDouble(&ok);
	status = status + "  Forward overlap:\t" + x_str + "%\n";
	status = status + "  Side overlap:\t" + y_str + "%\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//输入起始坐标
void LineDesignerDemo::pushButton_6_Clicked()
{
	QString start_x_str = this->ui.lineEdit_11->text();
	start_x = start_x_str.toDouble(&ok);
	QString start_y_str = this->ui.lineEdit_12->text();
	start_y = start_y_str.toDouble(&ok);
	status = status + "  x0 =\t" + start_x_str + "\n";
	status = status + "  y0 =\t" + start_y_str + "\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//输出采样坐标
void LineDesignerDemo::pushButton_output_Clicked()
{
	status = status + "Output points:\n";

	double end_x = start_x + Length;
	double end_y = start_y + Width;
	double im, am;
	am = ceil((end_y - start_y) / ((1 - x / 100)*L));
	im = ceil((end_x - start_x) / ((1 - y / 100)*L));	//im为一行的拍摄点个数，am为一列的拍摄点个数
	double xi[1000], yj[1000];	//xi,yj为拍摄点的坐标值
	xi[0] = start_x;
	yj[0] = start_y;
	int i = 0, j = 0;
	for (; i <= im; i++)
	{
		xi[i + 1] = xi[i] + (1 - y / 100)*L;
	}
	for (; j <= am; j++)
	{
		yj[j + 1] = yj[j] + (1 - x / 100)*L;
	}
	for (i = 0; i <= im; i++)	//输出按航迹飞行的坐标值
	{
		if (i % 2 == 0)	//偶数列时，航迹方向为y轴正向
		{
			for (j = 0; j <= am; j++)
			{
				sprintf_s(buffer, "%f", xi[i]);
				QString temp_x = buffer;
				sprintf_s(buffer, "%f", yj[j]);
				QString temp_y = buffer;
				status = status + "(" + temp_x + ", " + temp_y + ")\n";
			}
		}
		else    //奇数列时，航迹方向为y轴负方向
		{
			for (j = am; j >=0; j--)
			{
				sprintf_s(buffer, "%f", xi[i]);
				QString temp_x = buffer;
				sprintf_s(buffer, "%f", yj[j]);
				QString temp_y = buffer;
				status = status + "(" + temp_x + ", " + temp_y + ")\n";
			}
		}
	}
	this->ui.textEdit->setText(status);
}