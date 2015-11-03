#include "LoggingServer.hpp"
#include <QException>

typedef void ( CALLING_CONVENTION SetupLoggingFunction )( LogFunction *logFunction, void *userData );

//Version LOGGINGSERVER_API CALLING_CONVENTION GetServerVersion();

typedef BOOL ( CALLING_CONVENTION StartServerFunction )( const wchar_t messageAnalyserHostName[], int messageAnalyserPortNumber );

typedef BOOL ( CALLING_CONVENTION StopServerFunction )();

typedef BOOL ( CALLING_CONVENTION StartTestCaseLoggingFunction )( const wchar_t projectExplorerHostName[], int projectExplorerPortNumber,
	const wchar_t traceSapHostName[], int traceSapPortNumber, const wchar_t messageLogFilePath[] );

typedef BOOL ( CALLING_CONVENTION StopTestCaseLoggingFunction )();

class UnresolvedSymbol : public QException {
	public:
		UnresolvedSymbol( const QString &symbol ) noexcept {
			_symbol = symbol;
		}

		QString symbol() const {
			return _symbol;
		}

	private:
		QString _symbol;

};

static SetupLoggingFunction *SetupLogging;
static StartServerFunction *StartServer;
static StopServerFunction *StopServer;
static StartTestCaseLoggingFunction *StartTestCaseLogging;
static StopTestCaseLoggingFunction *StopTestCaseLogging;

template < typename T >
	static T resolveFunction( QLibrary *library, const char *symbol ) {
		T function = reinterpret_cast< T >( library->resolve( symbol ));
		if ( function == nullptr )
			throw UnresolvedSymbol( symbol );

		return function;
	}

QLibrary LoggingServer::s_dll;

bool LoggingServer::load( const QString &fileName ) {
	QString error;
	try {
		s_dll.setFileName( fileName );
		if ( s_dll.load() ) {
			SetupLogging = resolveFunction< SetupLoggingFunction * >( &s_dll, "_SetupLogging@8" );
			StartServer = resolveFunction< StartServerFunction * >( &s_dll, "_StartServer@8" );
			StopServer = resolveFunction< StopServerFunction * >( &s_dll, "_StopServer@0" );
			StartTestCaseLogging = resolveFunction< StartTestCaseLoggingFunction * >( &s_dll, "_StartTestCaseLogging@20" );
			StopTestCaseLogging = resolveFunction< StopTestCaseLoggingFunction * >( &s_dll, "_StopTestCaseLogging@0" );

			return true;
		} else {
			error = s_dll.errorString();
			return false;
		}
	} catch ( UnresolvedSymbol & ) {
		error = s_dll.errorString();
		return false;
	}
}

bool LoggingServer::unload() {
	return s_dll.unload();
}
