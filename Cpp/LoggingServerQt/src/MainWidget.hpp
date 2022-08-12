#pragma once

#include <QMainWindow>

class QLocale;
class ControllerWidget;
class SettingsWidget;

class MainWidget : public QMainWindow {
	Q_OBJECT

	public:
		MainWidget( const QLocale &locale, QWidget *parent = 0);
		~MainWidget();

	signals:

	public slots:

	private:
		ControllerWidget *_controller;
		SettingsWidget *_settings;
};
