#include "MainWidget.hpp"
#include <QApplication>
#include <QInputMethod>

#include <pera_software/company/PERA.hpp>

int main(int argc, char *argv[]) {

	QString name = pera_software::company::PERA::NAME;

	QApplication application( argc, argv );
	QStringList languages = QLocale::system().uiLanguages();
	QLocale locale( languages.at( 0 ));

	MainWidget mainWidget( locale );
	mainWidget.show();

	return application.exec();
}
