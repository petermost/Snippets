package com.pera_software;

import java.io.*;

import org.apache.commons.net.ftp.*;

// Try to upload it:

//String passWord = readPassWord( "FTP password" );
//if ( passWord != null ) {
//	try ( Upload upload = new Upload( "PERA-Software.com", "p7741038", passWord )) {
//		upload.upload( zipFileName );
//	} catch ( Exception exception) {
//		Console.printError( "Uploading failed with: %s",  exception.getMessage() );
//	}
//}

public class Upload implements Closeable
{
	private FTPHTTPClient _ftp;

	public Upload( String serverName, String userName, String passWord )
		throws Exception
	{
		if ( passWord.isEmpty() )
			passWord = "xxx";

		_ftp = new FTPHTTPClient( "proxy-hostname", 80, "user-name", "user-password" );
		_ftp.connect( serverName );
		_ftp.login( userName, passWord );
		_ftp.enterLocalActiveMode();
	}

	@Override
	public void close() throws IOException
	{
		_ftp.logout();
		_ftp.disconnect();
	}

	public boolean upload( String fileName )
		throws Exception
	{
		try ( InputStream fileInputStream = new FileInputStream( fileName )) {
			return _ftp.storeFile( "/backup/" + fileName, fileInputStream );
		}
	}
}
