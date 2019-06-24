#include <QWidget>
#include "applabel.h"
#include <QObject>

class Widget: public QWidget {

	Q_OBJECT

	public:
		explicit Widget();

	private:
		AppLabel*** m_Label;
		bool isPrevX = false;
        int mBoxCount = 4;
	
		enum GameCheckRoutine {
			RowCheck,
			ColCheck,
			DiagLeftCheck,
			DiagRightCheck
		};
		
		void funcCheckWin(int row, int col/*, GameCheckRoutine gamecheck*/);
		void funcReset();

	private slots:
		void slotLabelClicked();
};
