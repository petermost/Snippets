package com.pera_software;
import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.*;

import com.pera_software.aidkit.*;
import com.pera_software.aidkit.Console;


public class OldFileDeleter implements FileVisitor< Path >
{
	OldFileDeleter( Path startDirectory, boolean simulate  )
	{
		startDirectory_ = startDirectory;
		simulate_ = simulate;
	}

	private static final long TODAY = System.currentTimeMillis();

	private static boolean isFromToday( BasicFileAttributes fileAttributes )
	{
		long fileCreationTime = fileAttributes.creationTime().toMillis();
		return ( TODAY - fileCreationTime ) < TimeConstants.MILLISECONDS_PER_DAY;
	}

	private void deleteFile( Path file )
	{
		try {
			if ( !simulate_ )
				Files.delete( file );
			Console.printStatus( "Deleted '%s'", file );
		} catch ( DirectoryNotEmptyException exception ) {
			// Can happen if visitFile() determined that a file shouldn't be deleted and then
			// postVisitDirectory() tries to delete the directory in which this file resides.
		} catch ( Exception exception ) {
			// Unfortunately getMessage() only returns the complete file path for the file that failed
			// so it doesn't help us to print it:

			Console.printError( "Deleting of '%s' failed because '%s'!", file, exception.getClass().getSimpleName() );
		}
	}

	@Override
	public FileVisitResult preVisitDirectory( Path directory, BasicFileAttributes attributes )
	{
		// Skip directories which have been created today:

		if ( !isFromToday( attributes ))
			return FileVisitResult.CONTINUE;
		else {
			Console.printError( "Skipping directory '%s'", directory );
			return FileVisitResult.SKIP_SUBTREE;
		}
	}

	@Override
	public FileVisitResult visitFile(Path file, BasicFileAttributes attributes)
	{
		// Skip files which have been created today:

		if ( !isFromToday( attributes ))
			deleteFile( file );
		else
			Console.printError( "Skipping file '%s'", file );

		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult postVisitDirectory(Path directory, @SuppressWarnings("unused") IOException exception)
	{
		// Don't try to delete the start directory:

		if ( startDirectory_.equals( directory ))
			Console.printError( "Skipping start directory '%s'", directory );
		else {
			// If preVisitDirectory has allowed to visit this directory then it is OK to delete it:

			deleteFile( directory );
		}
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFileFailed(Path file, IOException exception)
	{
		Console.printError( "Deleting of '%s' failed because '%s'!", file, exception.getClass().getSimpleName() );

		return FileVisitResult.CONTINUE;
	}
	private Path startDirectory_;
	private boolean simulate_;
}
