#include "widget.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

Widget::Widget()
{
	setGeometry(10,10,600,450);
	setWindowTitle("Tic-Tac-Toe");
	
	m_Label = new AppLabel**[mBoxCount];	

	QGridLayout* grid = new QGridLayout(this);

	for(int i=0; i<mBoxCount;i++)
        {
		m_Label[i] = new AppLabel*[mBoxCount];
		for (int j=0;j<mBoxCount;j++)
		{
	                m_Label[i][j] = new AppLabel( this);
			m_Label[i][j]->setFrameStyle(QFrame::Panel | QFrame::Sunken);
			m_Label[i][j]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			m_Label[i][j]->setFont(QFont(QString("Helvetica"),25));
			m_Label[i][j]->setObjectName("Label:"+QString::number(i)+":"+QString::number(j));
			grid->addWidget(m_Label[i][j], i, j);

			connect (m_Label[i][j], SIGNAL(clicked()), this, SLOT(slotLabelClicked()));
		}
        }	
	QLabel* playerLabel = new QLabel("Player1: X    |    Player2: O", this);
	playerLabel->setFont(QFont(QString("Helvetical"), 20));
	grid->addWidget(playerLabel, mBoxCount, 0, 1, mBoxCount);
}

void Widget::slotLabelClicked()
{
	QString objName = QObject::sender()->objectName();
	int row = objName.section(":",1,1).toInt();
	int col = objName.section(":",2,2).toInt();

	if (isPrevX)
		m_Label[row][col]->setValue(AppLabel::ValueO);
	else
		m_Label[row][col]->setValue(AppLabel::ValueX);

	isPrevX = !isPrevX;
	funcCheckWin(row,col);
}

void Widget::funcCheckWin(int row, int col /*, GameCheckRoutine gamecheck*/)
{
	int prevText=m_Label[row][0]->getValue();
	bool winFound = true;

	for (int i=0; i<mBoxCount; i++)	
	{
		int newText = m_Label[row][i]->getValue();
		if (prevText != newText)
		{
			winFound = false;
			break;
		}
		prevText = newText;
	}

	if (winFound)
	{
		for (int i=0;i<mBoxCount;i++)
		{
			m_Label[row][i]->setStyleSheet("QLabel{background-color:lightgreen;color:brown;}");
		}
		int ret = QMessageBox::question(this, "Wins!", "Start new game?", QMessageBox::Yes | QMessageBox::No );
		if ( ret == QMessageBox::Yes)
			funcReset();
		else
			this->close();
		return;
	}

	prevText = m_Label[0][col]->getValue();
	winFound = true;
	for (int i=0; i<mBoxCount; i++)	
	{
		int newText = m_Label[i][col]->getValue();
		if (prevText != newText)
		{
			winFound = false;
			break;
		}
		prevText = newText;
	}
	
	if (winFound)
	{
		for (int i=0;i<mBoxCount;i++)
		{
			m_Label[i][col]->setStyleSheet("QLabel{background-color:lightgreen;color:brown;}");
		}
		int ret = QMessageBox::question(this, "Wins!", "Start new game?", QMessageBox::Yes | QMessageBox::No );
		if ( ret == QMessageBox::Yes)
			funcReset();
		else
			this->close();
		return;
	}

	if (row == col)
	{
		prevText = m_Label[0][0]->getValue();
		winFound = true;
		for (int i=0;i<mBoxCount;i++)
		{
			int newText = m_Label[i][i]->getValue();
			if (prevText != newText)
			{
				winFound = false;
				break;
			}
			prevText = newText;
		}
		if (winFound)
		{
			for (int i=0;i<mBoxCount;i++)
			{
				m_Label[i][i]->setStyleSheet("QLabel{background-color:lightgreen;color:brown;}");
			}
			int ret = QMessageBox::question(this, prevText+" Wins!", "Start new game?", QMessageBox::Yes | QMessageBox::No );
			if ( ret == QMessageBox::Yes)
				funcReset();
			else
				this->close();
			return;
		}
	}
	
	if ( row+col == mBoxCount-1)	
	{
		prevText = m_Label[0][mBoxCount-1]->getValue();
		winFound = true;
		for (int i=0;i<mBoxCount; i++)
		{
			int newText = m_Label[i][mBoxCount-i-1]->getValue();
			if (prevText != newText) 
			{
				winFound = false;
				break;
			}
			prevText = newText;
		}
		if (winFound)
		{
			for (int i=0;i<mBoxCount;i++)
			{
				m_Label[i][mBoxCount-i-1]->setStyleSheet("QLabel{background-color:lightgreen;color:brown;}");
			}
			int ret = QMessageBox::question(this, prevText+" Wins!", "Start new game?", QMessageBox::Yes | QMessageBox::No );
			if ( ret == QMessageBox::Yes)
				funcReset();
			else
				this->close();
			return;
		}	
	}
	
	m_Label[row][col]->setEnabled(false);
}

void Widget::funcReset()
{
	for (int i=0;i<mBoxCount; i++)
	{
		for ( int j=0;j<mBoxCount;j++)
		{
			m_Label[i][j]->setValue(AppLabel::ValueNone);
			m_Label[i][j]->setEnabled(true);
		}
	}
	isPrevX = false;
}
