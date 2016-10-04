#ifndef LINEDESIGNERDEMO_H
#define LINEDESIGNERDEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_linedesignerdemo.h"

class LineDesignerDemo : public QMainWindow
{
	Q_OBJECT

public:
	LineDesignerDemo(QWidget *parent = 0);
	~LineDesignerDemo();

private:
	Ui::LineDesignerDemoClass ui;
private slots:
	void buttonClicked();
};

#endif // LINEDESIGNERDEMO_H
