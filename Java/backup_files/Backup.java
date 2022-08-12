package com.pera_software;


import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.*;
import java.util.zip.*;

import com.pera_software.aidkit.Console;

//##############################################################################

public class Backup extends SimpleFileVisitor< Path > implements Closeable
{
	private ZipOutputStream _zipStream;
	private PathMatcher _pathMatcher;
	private String _fileName;

	//============================================================================

	public Backup( String backupFileName )
		throws FileNotFoundException
	{
		_fileName = backupFileName;
		Console.printStatus( "Creating: " + _fileName );
		_zipStream = new ZipOutputStream( new FileOutputStream( _fileName ));
	}

	//============================================================================

	@Override
	public void close()
		throws IOException
	{
		_zipStream.close();
		Console.printStatus( "Closed: " + _fileName );
	}

	//============================================================================

	public void backup( String wildCardPath )
	{
		try {
			if ( wildCardPath.contains( "*" ) || wildCardPath.contains( "?" )) {
				// Extract the path so we know where to start and get the name which contains the
				// wildcard so we know what to store:

				File wildCardFile = new File( wildCardPath );
				String parentDirectory = wildCardFile.getParent();
				String wildCardPattern = wildCardFile.getName();
				_pathMatcher = FileSystems.getDefault().getPathMatcher( "glob:" + wildCardPattern );
				Files.walkFileTree( Paths.get( parentDirectory ), this );
			} else
				storeFile( new File( wildCardPath ));
		} catch ( FileNotFoundException exception ) {
			Console.printError( "File/Directory not found: " + wildCardPath );
		} catch ( IOException exception ) {
			Console.printError( "File/Directory '%s' not stored because: '%s'", wildCardPath, exception.getMessage() );
		}
	}

	//============================================================================

	@Override
	public FileVisitResult visitFile( Path file, BasicFileAttributes attrs)
		throws IOException
	{
		if ( _pathMatcher.matches( file.getFileName() ))
			storeFile( file.toFile() );

		return super.visitFile( file, attrs );
	}

	//============================================================================

	private static byte buffer[] = new byte[ 8192 ];

	private void storeFile( File file )
		throws FileNotFoundException, IOException
	{
		Console.printStatus( "Storing: " + file );
		try ( FileInputStream inputStream = new FileInputStream( file )) {
			_zipStream.putNextEntry( new ZipEntry( file.getCanonicalPath() ));

			// Copy the content to the zip stream:

			int length;
			while (( length = inputStream.read( buffer )) > 0 )
				_zipStream.write( buffer, 0, length );

			_zipStream.closeEntry();
		}
	}


}

