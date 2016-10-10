#include "linedesignerdemo.h"

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
	x = 0, y = 0, x_count = 1, y_count = 1, long_dist = 0, short_dist = 0;
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
	status = status + "  f = " + f_str + "cm\n";
	status = status + "  x0 = " + x0_str + "cm\n";
	status = status + "  y0 = " + y0_str + "cm\n";
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
	status = status + "  Length = " + Length_str + "m\n";
	status = status + "  Width = " + Width_str + "m\n";
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
	status = status + "  Height = " + Height_str + "m\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//计算比例尺
void LineDesignerDemo::pushButton_4_Clicked()
{
	QString Height_str = this->ui.lineEdit_9->text();
	Height = Height_str.toDouble(&ok);
	ratio = 100 * Height / f;
	sprintf_s(buffer, "%f", ratio);
	QString ratio_str = buffer;
	status = status + "  Ratio = 1: " + ratio_str + "\n";
	status += "----------\n";
	this->ui.textEdit->setText(status);
}
//输入视场角，获得像幅和对应地幅
void LineDesignerDemo::pushButton_2_Clicked()
{
	QString angle_str = this->ui.lineEdit_2->text();
	angle = angle_str.toDouble(&ok);
	angle = angle*pi / 180;
	l = 2 * f * tan(angle / 2);
	L = 2 * Height * tan(angle / 2);
	sprintf_s(buffer, "%f", l);
	QString l_str = buffer;
	status = status + "  Image width: " + l_str + "cm\n";
	sprintf_s(buffer, "%f", L);
	QString L_str = buffer;
	status = status + "  Area width: " + L_str + "m\n";
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
	int count = 1;
	long_dist = 0, short_dist = 0;
	double L_temp = L;
	count = 1;
	while (L_temp < Width)
	{
		L_temp += (1 - y / 100)*L;
		count++;
	}
	long_dist = Length*count;
	L_temp = L;
	count = 1;
	while (L_temp < Length)
	{
		L_temp += (1 - y / 100)*L;
		count++;
	}
	short_dist = Width*count;
	if (long_dist < short_dist)
	{
		status += "  Fly along long side.\n";
		status += "----------\n";
		this->ui.textEdit->setText(status);
	} 
	else
	{
		status += "  Fly along short side.\n";
		status += "----------\n";
		this->ui.textEdit->setText(status);
	}
}