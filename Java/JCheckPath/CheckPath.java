package com.pera_software;

import java.nio.file.*;
import java.util.*;
import java.util.Arrays;
import com.pera_software.aidkit.collection.*;
import com.pera_software.aidkit.lang.*;
import com.pera_software.company.*;
import com.pera_software.aidkit.nio.file.Paths;
import com.pera_software.aidkit.system.*;

public class CheckPath {

	private static final String PATH_VARIABLE_NAME = "PATH";

	//==============================================================================================

	private static List< Path > findMissingPaths( List< Path > paths ) {
		List< Path > missingPaths = new ArrayList<>();
		for ( Path path : paths ) {
			if ( !Files.exists( path ))
				missingPaths.add( path );
		}
		return missingPaths;
	}

	//==============================================================================================

	public static void main( String arguments[] ) {

		System.out.printf( "%s\n", PERA.FULL_NAME );

		// Get the search path:

		Map< String, String > environment = System.getenv();
		String path = environment.getOrDefault( PATH_VARIABLE_NAME, Strings.EMPTY );
		if ( path.isEmpty() ) {
			System.err.printf( "Environmen variable '%s' not found!", PATH_VARIABLE_NAME );
			return;
		}

		List< Path > paths = Paths.get( Arrays.asList( path.split( SystemProperties.getPathSeparator().get() )));

		// Show duplicated paths in PATH:

		List< Path > duplicatedPaths = Lists.findDuplicates( paths );
		if ( duplicatedPaths.isEmpty() )
			System.out.println( "No duplicated path in PATH found." );
		else {
			for ( Path duplicatedPath : duplicatedPaths )
				System.err.printf( "Duplicated path '%s' found!", duplicatedPath );
		}

		// Show non-existing paths in PATH:

		List< Path > missingPaths = findMissingPaths( paths );
		if ( missingPaths.isEmpty() )
			System.out.println( "No missing paths in PATH found." );
		else {
			for ( Path missingPath : missingPaths )
				System.err.printf( "Missing path: '%s' in PATH found!\n",  missingPath );
		}

		// Show non-existing path from the environment which end with '_HOME':

		List< String > homePaths = new ArrayList<>();
		for ( String key : environment.keySet() ) {
			if ( key.toUpperCase().endsWith( "_HOME" )) {
				String value = environment.get( key );
				homePaths.add( value );
			}
		}
		missingPaths = findMissingPaths( Paths.get( homePaths ));
		if ( missingPaths.isEmpty() )
			System.out.println( "No missing '_HOME' paths in environment found." );
		else {
			for ( Path missingPath : missingPaths )
				System.err.printf( "Missing _HOME path: '%s' in environment found!\n", missingPath );
		}
	}
}
