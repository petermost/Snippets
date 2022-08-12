#pragma once

#include <QLibrary>

class TcpIpEndPoint;

#define BOOL int
#define CALLING_CONVENTION __stdcall

typedef void ( CALLING_CONVENTION LogFunction )( int logLevel, const wchar_t loggerName[], const wchar_t loggerMessage[],
	void *userData );

class LoggingServer {
	public:
		static bool load( const QString &fileName );
		static bool unload();

		static void setupLogging( LogFunction *logFunction, void *userData );

		static bool startServer( const TcpIpEndPoint &messageAnalyserEndPoint );
		static bool stopServer();

		static bool startTestCase( const TcpIpEndPoint &projectExplorerEndPoint, const TcpIpEndPoint &traceSapEndPoint );
		static bool stopTestCase();

	private:
		static QLibrary s_dll;
};
