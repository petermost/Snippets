#include "ControllerWidget.hpp"
#include "Icons.hpp"
#include "Utils.hpp"
#include <QIcon>
#include <QFile>
#include <QLocale>
#include <QGroupBox>
#include <QTableView>
#include <QPushButton>
#include <QBoxLayout>
#include <QButtonGroup>

ControllerWidget::ControllerWidget( const QLocale &locale, QWidget *parent )
	: QWidget( parent ) {

	// Setup the start server button:

	_startServerButton = new QPushButton( tr( "[A] Start" ), this );
	_startServerButton->setShortcut( Qt::Key_A );
	connect( _startServerButton, &QPushButton::clicked, this, &ControllerWidget::startServer );

	// Setup the stop server button:

	_stopServerButton = new QPushButton( tr( "[S] Stop" ), this );
	_stopServerButton->setShortcut( Qt::Key_S );
	connect( _stopServerButton, &QPushButton::clicked, this, &ControllerWidget::stopServer );

	// Setup the start test case button:

	if ( locale == QLocale::German ) {
		_startTestCaseButton = new QPushButton( "[Y] Start" );
		_startTestCaseButton->setShortcut( Qt::Key_Y );
	} else {
		_startTestCaseButton = new QPushButton( "[Z] Start" );
		_startTestCaseButton->setShortcut( Qt::Key_Z );
	}
	connect( _startTestCaseButton, &QPushButton::clicked, this, &ControllerWidget::startTestCase );

	// Setup the stop test case button:

	_stopTestCaseButton = new QPushButton( "[X] Stop" );
	_stopTestCaseButton->setShortcut( Qt::Key_X );
	connect( _stopTestCaseButton, &QPushButton::clicked, this, &ControllerWidget::stopTestCase );

	// Layout the buttons:

	QGroupBox *serverButtons = newHGroupBox( tr( "Server" ), { _startServerButton, _stopServerButton });
	QGroupBox *testCaseButtons = newHGroupBox( tr( "Testcase" ), { _startTestCaseButton, _stopTestCaseButton });

	QLayout *controlButtons = newHBoxLayout({ serverButtons, testCaseButtons });

	_logView = new QTableView;

	QGroupBox *messagesGroup = newHGroupBox( "Messages", { _logView });

	QVBoxLayout *layout = new QVBoxLayout( this );
	layout->addLayout( controlButtons );
	layout->addWidget( messagesGroup );
	setLayout( layout );
}

ControllerWidget::~ControllerWidget() {
}
