#include "TcpIpEdit.hpp"
#include "Utils.hpp"
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QIntValidator>
#include <initializer_list>

using namespace std;

TcpIpEdit::TcpIpEdit( const TcpIpEndPoint &endPoint, QWidget *parent)
	: QWidget(parent) {

	_hostNameEdit = new QLineEdit( endPoint.hostName(), parent );

	QLabel *colonLabel = new QLabel( tr( ":" ), parent );

	_portNumberEdit = new QLineEdit( QString::number( endPoint.portNumber() ), parent );
	_portNumberEdit->setValidator( new QIntValidator( 0, UINT16_MAX ));

	setLayout( newHBoxLayout({ _hostNameEdit, colonLabel, _portNumberEdit }, parent ));
}

TcpIpEdit::~TcpIpEdit() {
}

TcpIpEndPoint TcpIpEdit::endPoint() const {
	return TcpIpEndPoint( _hostNameEdit->text(), _portNumberEdit->text().toUShort() );
}
