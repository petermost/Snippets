package com.pera_software;

import java.nio.file.*;
import java.util.*;
import com.pera_software.aidkit.Console;
import com.pera_software.aidkit.nio.file.Paths;
import com.pera_software.aidkit.visualstudio.*;

public class ProjectFileChecker {

	//==============================================================================================

	public static void main( String arguments[] ) throws Exception {
		Console.printStatus( "CheckProjectFiles V1.1 (c) by P. Most, PERA Software Solutions GmbH" );
		Console.printStatus( "Checking for missing files..." );
		Console.printStatus( "Checking for 'treat warnings as errors' switch..." );
		if ( !Settings.parseCommandLine( arguments ) ) {
			showUsage( Settings.usage() );
			return;
		}
		// Iterate over the given solution file names and check the source files existence:

		for ( String solutionFileName : Settings.solutionFileNames() ) {
			SolutionFile solutionFile = new SolutionFile( Paths.get( solutionFileName ) );
			List< ProjectFile > projectFiles = solutionFile.loadProjects();

			Console.printStatus( "Checking solution file '%s'", solutionFile.path() );

			// Get the output directories from the projects:

			for ( ProjectFile projectFile : projectFiles ) {
				Console.printStatus( "Checking project file '%s'", projectFile.path() );

				List< Path > sourceFiles = projectFile.getSourceFiles();
				checkForMissingSourceFiles( sourceFiles );

				checkForMissingTreatWarningsAsErrorsSwitch( projectFile );
			}
		}
		Console.printStatus( "Finished checking." );
	}

	//==============================================================================================

	private static void checkForMissingSourceFiles( List< Path > sourceFiles ) {
		for ( Path sourceFile : sourceFiles ) {
			if ( sourceFile.toFile().exists() ) {
				if ( Settings.isVerbose() ) {
					Console.printStatus( "Source file '%s' exists.", sourceFile );
				}
			} else {
				Console.printError( "Source file '%s' is missing!",  sourceFile );
			}
		}
	}

	//==============================================================================================

	private static void checkForMissingTreatWarningsAsErrorsSwitch( ProjectFile projectFile ) throws Exception {
		if ( projectFile instanceof CSharpProjectFile ) {
			if ( !projectFile.getTreatWarningsAsErrors() ) {
				Console.printError( "Switch 'treat warnings as errors' not set!" );
			}
		}
	}

	//==============================================================================================

	private static void showUsage( List< String > usageLines ) {
		Console.printError( "Usage:" );
		for ( String usageLine : usageLines ) {
			Console.printError( "\t%s", usageLine );
		}
	}
}
