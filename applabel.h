#include <QLabel>
#include <QObject>

class AppLabel: public QLabel
{
	Q_OBJECT
	public:
		using QLabel::QLabel;
	
		~AppLabel();
		enum Value
		{
			ValueX,
			ValueO,
			ValueNone
		};

		void setValue(Value );
		int getValue();

	private:
		Value mVal=ValueNone;
	
	signals:
		void clicked();
	
	protected:
		void mousePressEvent(QMouseEvent* event);
	
};
