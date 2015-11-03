#include "SettingsWidget.hpp"
#include "Utils.hpp"
#include "TcpIpEdit.hpp"
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QBoxLayout>
#include <QFormLayout>

static const QString LOCAL_HOST( QStringLiteral( "localhost" ));

static const TcpIpEndPoint MESSAGE_ANALYSER_END_POINT( LOCAL_HOST, 44800 );

static const TcpIpEndPoint TRACE_SAP_END_POINT( LOCAL_HOST, 44000 );

static const TcpIpEndPoint PROJECT_EXPLORER_END_POINT( LOCAL_HOST, 44801 );


SettingsWidget::SettingsWidget(QWidget *parent)
	: QWidget(parent) {

	_messageAnalyserTcpIpEdit = new TcpIpEdit( MESSAGE_ANALYSER_END_POINT, this );
	_projectExplorerTcpIpEdit = new TcpIpEdit( PROJECT_EXPLORER_END_POINT, this );
	_traceSapTcpIpEdit = new TcpIpEdit( TRACE_SAP_END_POINT, this );
	_messageLogFileEdit = new QLineEdit( "messagelog.rsmsglog" );

	QFormLayout *formLayout = new QFormLayout( this );
	formLayout->addRow( tr( "&Message Analyser:" ), _messageAnalyserTcpIpEdit );
	formLayout->addRow( tr( "&Project Explorer:" ), _projectExplorerTcpIpEdit );
	formLayout->addRow( tr( "&Trace-SAP:" ), _traceSapTcpIpEdit );
	formLayout->addRow( tr( "&Logfile:" ), _messageLogFileEdit );

	setLayout( formLayout );
}


SettingsWidget::~SettingsWidget() {
}

TcpIpEndPoint SettingsWidget::messageAnalyserEndPoint() const {
	return _messageAnalyserTcpIpEdit->endPoint();
}

TcpIpEndPoint SettingsWidget::projectExplorerEndPoint() const {
	return _projectExplorerTcpIpEdit->endPoint();
}

TcpIpEndPoint SettingsWidget::traceSapEndPoint() const {
	return _traceSapTcpIpEdit->endPoint();
}
