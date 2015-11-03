#pragma once

class QLocale;
class QTableView;
class QPushButton;

#include <QWidget>

class ControllerWidget : public QWidget {
	Q_OBJECT
	public:
		ControllerWidget( const QLocale &locale, QWidget *parent = nullptr );
		~ControllerWidget();

	signals:
		void startServer();
		void stopServer();

		void startTestCase();
		void stopTestCase();

	public slots:

	private:
		QPushButton *_startServerButton;
		QPushButton *_stopServerButton;
		QPushButton *_startTestCaseButton;
		QPushButton *_stopTestCaseButton;

		QTableView *_logView;
};
