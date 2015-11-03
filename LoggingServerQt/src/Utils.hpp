#pragma once

#include <initializer_list>

class QString;
class QWidget;
class QGroupBox;
class QHBoxLayout;
class QVBoxLayout;

QHBoxLayout *newHBoxLayout( std::initializer_list< QWidget * > widgets, QWidget *parent = nullptr );
QVBoxLayout *newVBoxLayout( std::initializer_list< QWidget * > widgets, QWidget *parent = nullptr );

QGroupBox *newHGroupBox( const QString &title, std::initializer_list< QWidget * > widgets, QWidget *parent = nullptr );
QGroupBox *newVGroupBox( const QString &title, std::initializer_list< QWidget * > widgets, QWidget *parent = nullptr );
