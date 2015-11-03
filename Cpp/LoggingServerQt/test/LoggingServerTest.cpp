#include <QString>
#include <QtTest>
#include "../src/LoggingServer.hpp"
#include <windows.h>

class LoggingServerTest : public QObject
{
		Q_OBJECT

	public:
		LoggingServerTest();

	private Q_SLOTS:
		void testLoad();
};

LoggingServerTest::LoggingServerTest()
{
}

void LoggingServerTest::testLoad()
{
	SetDllDirectory( L"C:\\JazzMarsSandbox\\deploy\\Debug\\lib\\" );
	QVERIFY( LoggingServer::load( "C:\\JazzMarsSandbox\\deploy\\Debug\\lib\\LoggingServer.dll" ));
}

QTEST_APPLESS_MAIN(LoggingServerTest)

#include "LoggingServerTest.moc"
