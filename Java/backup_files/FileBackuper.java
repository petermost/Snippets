package com.pera_software;

import java.io.*;
import java.util.*;

import com.pera_software.aidkit.*;

// To replace backslash with forward slash '%s:\\:/:gc'

//##############################################################################

public class FileBackuper
{
	private static final String JAZZ_WORKSPACE_DIRECTORY = "C:/JazzWorkspaceSeparationDevelopment/";
	private static final String CLEARCASE_SNAPSHOT_DIRECTORY = "C:/ClearCaseViews/mcttools_view/";

	private static final String CPLUSPLUS_WILDCARD = "*.{h,hpp,cpp}";
	private static final String JAVA_WILDCARD = "*.java";

	private static final String FIREFOX_PROFILE_DIRECTORY = Platform.settingsDirectory() + "/Mozilla/Firefox/Profiles/v1w7219y.default";

	private static final String configurationFiles[] = {

		Platform.systemDrive() + "/AUTOEXEC.BAT",

		// Vim:

		Platform.programsDirectory() + "/Vim/_vimrc",
		Platform.programsDirectory() + "/Vim/vimfiles/after/syntax/c.vim",
		Platform.programsDirectory() + "/Vim/vimfiles/after/syntax/java.vim",
		Platform.programsDirectory() + "/Vim/vimfiles/after/colors/peter_most_minimal.vim",
		Platform.settingsDirectory() + "/Microsoft/Windows/SendTo/gVim.lnk",

		// Firefox settings and passwords:

		FIREFOX_PROFILE_DIRECTORY + "/places.sqlite",  // Bookmarks, Downloads and Browsing History:
		FIREFOX_PROFILE_DIRECTORY + "/bookmarks.html", // Exported Bookmarks (about:config 'browser.bookmarks.autoExportHTML')

		FIREFOX_PROFILE_DIRECTORY + "/prefs.js",       // Preferences/Settings
		FIREFOX_PROFILE_DIRECTORY + "/key3.db",        // Passwords
		FIREFOX_PROFILE_DIRECTORY + "/signons.sqlite", // Saved passwords
	};

	private static final String sourceFiles[] =  {
        // C++:

		JAZZ_WORKSPACE_DIRECTORY + "CMWmars/Utilities/UtilityCpp/" + CPLUSPLUS_WILDCARD,
		JAZZ_WORKSPACE_DIRECTORY + "CMWmars/Utilities/UtilityCppUnitTest/" + CPLUSPLUS_WILDCARD,

        // Java:

		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/java/com/rohde_schwarz/crtu/lib/calls/" + JAVA_WILDCARD,
		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/java/com/rohde_schwarz/crtu/lib/streams/" + JAVA_WILDCARD,
		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/java/com/rohde_schwarz/crtu/lib/util/" + JAVA_WILDCARD,
		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/java/com/rohde_schwarz/log4j/" + JAVA_WILDCARD,
		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/java/com/rohde_schwarz/meg/" + JAVA_WILDCARD,
		CLEARCASE_SNAPSHOT_DIRECTORY + "crtu_meg/modules/utilities/unittests/com/rohde_schwarz/" + JAVA_WILDCARD,

		// Misc:

		"O:/PMost_Privat/Snippets/*.*"
	};

	private static final String mediaFiles[] = {
		"O:/PMost_Privat/Bilder/*.*",
		"O:/PMost_Privat/Musik/*.*"
	};


	//============================================================================

	public static String makeIsoDate()
	{
		Calendar calendar = Calendar.getInstance();

		String isoDate = String.format( "%04d-%02d-%02d", calendar.get( Calendar.YEAR ),
			calendar.get( Calendar.MONTH ) + 1, calendar.get( Calendar.DAY_OF_MONTH ));

		return ( isoDate );
	}

	//============================================================================

//	private static String readPassWord( String prompt )
//	{
//		String passWord = "";
//
//		java.io.Console console = System.console();
//		if ( console == null )
//			return passWord;
//
//		char passWordCharacters[] = console.readPassword( "%s: ", prompt );
//		if ( passWordCharacters == null )
//			return passWord;
//
//		passWord = new String( passWordCharacters );
//		return passWord;
//	}

	//============================================================================

	private static void backupFiles( String zipFileNamePrefix, String wildCardPatterns[] )
		throws IOException
	{
		String zipFileName = zipFileNamePrefix + makeIsoDate() + ".zip";
		try ( Backup backup = new Backup( zipFileName )) {
			for ( String wildCardPattern : wildCardPatterns )
				backup.backup( wildCardPattern );
		}
	}

	//============================================================================

	public static void main( String arguments[] )
		throws IOException
	{
		// Backup all files to a zip file:

		backupFiles( "../Source_", sourceFiles );
		backupFiles( "../Configuration_", configurationFiles );
		backupFiles( "../Media_", mediaFiles );
	}
}
