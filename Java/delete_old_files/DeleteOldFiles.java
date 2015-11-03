package com.pera_software;

import java.io.*;
import java.nio.file.*;

import org.kohsuke.args4j.*;

import com.pera_software.aidkit.Console;


public class DeleteOldFiles
{
	@Option( name = "-s", aliases = "--simulate" )
	private boolean simulate_ = false;

	// Only delete named directories:
	@Argument( required = true, usage = "directory to delete must be explicitly named" )
	private String directory_ = "";

	public void doMain( String arguments[] )
		throws IOException
	{
		try {
			CmdLineParser parser = new CmdLineParser( this );
			parser.parseArgument( arguments );

			Path directory = Paths.get( directory_ );
			OldFileDeleter fileDeleter = new OldFileDeleter( directory, simulate_ );
			Files.walkFileTree( directory, fileDeleter );
		} catch ( CmdLineException cmdLineException ) {
			Console.printError( cmdLineException.getMessage() );
		}
	}


	public static void main( String arguments[] )
		throws Exception
	{
		new DeleteOldFiles().doMain( arguments );
	}
}
