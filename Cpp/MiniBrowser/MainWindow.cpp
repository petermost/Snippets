#include "MainWindow.hpp"
#include <QAction>
#include <QKeySequence>
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QWebView>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle( "Mini Qt-Browser ");

	QAction *exitAction = new QAction( "E&xit", this );
	exitAction->setShortcut( QKeySequence( "Ctrl+X" ));
	connect( exitAction, &QAction::triggered, QApplication::quit );

	QMenu *fileMenu = menuBar()->addMenu( "&File" );
	fileMenu->addAction( exitAction );

	QAction *aboutAction = new QAction( "&About...", this );

	QMenu *helpMenu = menuBar()->addMenu( "&Help" );
	helpMenu->addAction( aboutAction );

	QWebView *webView = new QWebView;
	webView->load( QUrl( "http://www.google.com" ));
	setCentralWidget( webView );
}

MainWindow::~MainWindow()
{

}
