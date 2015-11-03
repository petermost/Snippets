#pragma once

#include <QString>

class TcpIpEndPoint {
	public:
		TcpIpEndPoint();
		TcpIpEndPoint( const QString &hostName, quint16 portNumber );
		~TcpIpEndPoint();

		QString hostName() const;
		quint16 portNumber() const;

	private:
		QString _hostName;
		quint16 _portNumber;
};
