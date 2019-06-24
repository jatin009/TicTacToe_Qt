#include <QApplication>
#include "widget.h"

int main (int argc, char** argv)
{
	QApplication app(argc, argv);
	
	Widget wid;
	//widget.setGeometry(5,5,150,60);
	wid.show();
	app.exec();
}
