#pragma once

#include <QLibrary>
#include <wchar.h>
#include <w32api.h>

class TcpIpEndPoint;


class Controller : public QObject
{
	Q_OBJECT
	public:
		explicit Controller( QObject *parent = 0);
		~Controller();

	signals:

	public slots:

	private:
};
