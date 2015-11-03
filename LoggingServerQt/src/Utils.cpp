#include "Utils.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

template < typename T >
	T *newLayout( initializer_list< QWidget * > widgets, QWidget *parent )
	{
		auto *layout = new T( parent );
		for ( QWidget *widget : widgets )
			layout->addWidget( widget );

		return layout;
	}

template < typename T >
	QGroupBox *newGroupBox( const QString &title, initializer_list< QWidget * > widgets, QWidget *parent ) {
		QGroupBox *groupBox = new QGroupBox( title, parent );
		groupBox->setLayout( newLayout< T >( widgets, parent ));

		return groupBox;
	}

QHBoxLayout *newHBoxLayout(initializer_list< QWidget * > widgets , QWidget *parent) {
	return newLayout< QHBoxLayout >( widgets, parent );
}


QVBoxLayout *newVBoxLayout(initializer_list< QWidget * > widgets , QWidget *parent) {
	return newLayout< QVBoxLayout >( widgets, parent );
}


QGroupBox *newHGroupBox( const QString &title, initializer_list< QWidget * > widgets, QWidget *parent ) {
	return newGroupBox< QHBoxLayout >( title, widgets, parent );
}


QGroupBox *newVGroupBox( const QString &title, initializer_list< QWidget * > widgets, QWidget *parent ) {
	return newGroupBox< QVBoxLayout >( title, widgets, parent );
}
