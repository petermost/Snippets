#pragma once

#include <QWidget>

class TcpIpEdit;
class QLineEdit;
class TcpIpEndPoint;

class SettingsWidget : public QWidget {
	Q_OBJECT
	public:
		explicit SettingsWidget( QWidget *parent = nullptr );
		~SettingsWidget();

		TcpIpEndPoint messageAnalyserEndPoint() const;
		TcpIpEndPoint projectExplorerEndPoint() const;
		TcpIpEndPoint traceSapEndPoint() const;

	signals:

	public slots:

	private:
		TcpIpEdit *_messageAnalyserTcpIpEdit;
		TcpIpEdit *_projectExplorerTcpIpEdit;
		TcpIpEdit *_traceSapTcpIpEdit;

		QLineEdit *_messageLogFileEdit;
};
