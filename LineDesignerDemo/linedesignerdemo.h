#ifndef LINEDESIGNERDEMO_H
#define LINEDESIGNERDEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_linedesignerdemo.h"
#include <cmath>
#include <math.h>
#include <qpoint.h>

class LineDesignerDemo : public QMainWindow
{
	Q_OBJECT
protected:
	bool ok;						//默认所有输入合法
	char buffer[20];
	double f, x0, y0;
	double Width, Length;
	double ratio;
	double Height;
	double angle;
	double pi;
	double l, L;
	double x, y, x_count, y_count, long_dist, short_dist;
	double start_x, start_y;
	QString status;

public:
	LineDesignerDemo(QWidget *parent = 0);
	~LineDesignerDemo();

private:
	Ui::LineDesignerDemoClass ui;
private slots:
	void buttonClicked();
	void pushButton_3_Clicked();
	void pushButton_Clicked();
	void pushButton_4_Clicked();
	void pushButton_2_Clicked();
	void pushButton_5_Clicked();
	void pushButton_6_Clicked();
	void pushButton_output_Clicked();
};

#endif // LINEDESIGNERDEMO_H
