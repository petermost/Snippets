#include "TcpIpEndPoint.hpp"

TcpIpEndPoint::TcpIpEndPoint()
	: _hostName(), _portNumber( 0 ) {
}

TcpIpEndPoint::TcpIpEndPoint(const QString &hostName, quint16 portNumber)
	: _hostName( hostName ), _portNumber( portNumber ) {
}

TcpIpEndPoint::~TcpIpEndPoint() {
}

QString TcpIpEndPoint::hostName() const {
	return _hostName;
}

quint16 TcpIpEndPoint::portNumber() const {
	return _portNumber;
}

