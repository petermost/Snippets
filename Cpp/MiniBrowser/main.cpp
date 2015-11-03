#include "MainWindow.hpp"
#include <QApplication>
#include <QNetworkProxy>

int main(int argc, char *argv[])
{
	QNetworkProxy proxy;
	proxy.setType( QNetworkProxy::HttpProxy );
	proxy.setHostName( "proxy-emea.rsint.net" );
	proxy.setPort( 80 );
	proxy.setUser( "most" );
	proxy.setPassword( "hekundo28" );
	QNetworkProxy::setApplicationProxy(proxy);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
