#pragma once

#include "TcpIpEndPoint.hpp"
#include <QWidget>

class QLineEdit;

class TcpIpEdit : public QWidget {
	Q_OBJECT
	public:
		TcpIpEdit( const TcpIpEndPoint &, QWidget *parent = nullptr );
		~TcpIpEdit();

		TcpIpEndPoint endPoint() const;

	signals:

	public slots:

	private:
		TcpIpEndPoint _endPoint;

		QLineEdit *_hostNameEdit;
		QLineEdit *_portNumberEdit;
};
