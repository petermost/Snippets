#include "MainWidget.hpp"
#include "ControllerWidget.hpp"
#include "SettingsWidget.hpp"
#include <QLocale>
#include <QTabWidget>

using namespace std;

//##################################################################################################

MainWidget::MainWidget( const QLocale &locale, QWidget *parent )
	: QMainWindow( parent ) {

	setWindowTitle( "Logging Server Qt" );

	_controller = new ControllerWidget( locale, this );
	_settings = new SettingsWidget( this );

	QTabWidget *tabWidget = new QTabWidget( this );
	tabWidget->addTab( _controller, tr( "Control" ));
	tabWidget->addTab( _settings, tr( "Settings" ));

	setCentralWidget( tabWidget );
}


MainWidget::~MainWidget() {
}
