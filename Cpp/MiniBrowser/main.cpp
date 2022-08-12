#include "MainWindow.hpp"
#include <QApplication>
#include <QNetworkProxy>

int main(int argc, char *argv[])
{
	QNetworkProxy proxy;
	proxy.setType( QNetworkProxy::HttpProxy );
	proxy.setHostName( "proxy-hostname" );
	proxy.setPort( 80 );
	proxy.setUser( "user-name" );
	proxy.setPassword( "pass-word" );
	QNetworkProxy::setApplicationProxy(proxy);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
