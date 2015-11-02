#include <QDir>
#include <QFile>
#include <QVector>
#include <QFileInfo>
#include <QDirIterator>
#include <QCoreApplication>
#include <QXmlStreamReader>
#include <iostream>

using namespace std;

QVector< QString > findProjectFileNames( const QString &startDirectoryName )
{
	QVector< QString > projectFileNames;

	QDirIterator directory( startDirectoryName, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot );
	while ( directory.hasNext() ) {
		QString fileName = directory.next();
		if ( directory.fileInfo().isDir() )
			projectFileNames << findProjectFileNames( fileName );
		else if ( fileName.endsWith( ".vcxproj", Qt::CaseInsensitive )) {
			cout << "Found C++ project file: " << qPrintable( fileName ) << endl;
			projectFileNames.append( fileName );
		}
	}
	return projectFileNames;
}


QVector< QString > findIncludeFileNames( const QString &projectFileName )
{
	QVector< QString > includeFileNames;

	QFile projectFile( projectFileName );
	if ( !projectFile.open( QFile::ReadOnly )) {
		cerr << "Project file " << qPrintable( projectFileName ) << " doesn't exist!" << endl;
		return includeFileNames;
	}

	QXmlStreamReader xmlReader( &projectFile );
	while ( !xmlReader.atEnd() && !xmlReader.hasError() ) {
		auto token = xmlReader.readNext();
		if ( token == QXmlStreamReader::StartElement ) {
			if ( xmlReader.name() == "ClInclude" ) {
				auto attributes = xmlReader.attributes();
				auto includeFileName = attributes.value( "Include" );
				if ( !includeFileName.isEmpty() )
					includeFileNames.append( includeFileName.toString() );
			}
		}
	}
	return includeFileNames;
}


QVector< QString > findMissingIncludeFiles( const QString &projectFileName, const QVector< QString > &includeFileNames )
{
	QVector< QString > missingIncludeFiles;

	QDir projectDirectory( QFileInfo( projectFileName ).dir() );
	for ( const QString &includeFileName : includeFileNames ) {
		QString includeFilePath( projectDirectory.filePath( includeFileName ));
		if ( !QFile::exists( includeFilePath ))
			missingIncludeFiles.append( includeFileName );
	}
	return missingIncludeFiles;
}


int main( int argc, char *argv[] )
{
	QCoreApplication application( argc, argv );

	// Retrieve the referenced include file names:

	if ( argc != 2 ) {
		cerr << "Missing start directory!" << endl;
		return EXIT_FAILURE;
	}
	QString startDirectory = argv[ 1 ];
	QVector< QString > projectFileNames = findProjectFileNames( startDirectory );
	for ( const QString &projectFileName : projectFileNames ) {
		QVector< QString > includeFileNames = findIncludeFileNames( projectFileName );
		QVector< QString > missingIncludeFiles = findMissingIncludeFiles( projectFileName, includeFileNames );
		cout << "Project file " << qPrintable( projectFileName ) << " :" << endl;
		for ( const QString &missingIncludeFile : missingIncludeFiles )
			cout << "Include file " << qPrintable( missingIncludeFile ) << " is missing!" << endl;
	}
	return EXIT_SUCCESS;
}
