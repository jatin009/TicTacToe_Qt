#include "applabel.h"

void AppLabel::mousePressEvent(QMouseEvent*)
{	
	emit clicked();
}

AppLabel::~AppLabel()
{}

void AppLabel::setValue(Value val)
{
	if (val == ValueX)
	{
		setText("X");
        setStyleSheet("QLabel{background-color:lightyellow;color:black;}");
        mVal = ValueX;
	}
	else if ( val == ValueO)
	{
		setText("O");
		setStyleSheet("QLabel{background-color:lightsteelblue;color:black;}");
		mVal = ValueO;
	}
	else if (val == ValueNone)
	{
		clear();
		setStyleSheet("QLabel{background-color:white;color:black;}");
        mVal = ValueNone;
	}
}

int AppLabel::getValue()
{
	return mVal;
}
