#include "linedesignerdemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LineDesignerDemo w;
	w.show();
	return a.exec();
}
