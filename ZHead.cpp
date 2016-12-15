#include "common.h"
#include "ZHead.h"
#include "XUnzip.h"
#include <string>
#include <list>
using namespace std;

 

//Fuction：create a directory accorting to the path of the directory.
BOOL CreateDirectorys( LPCSTR lpszPath )
{    
    return QDir().mkpath(lpszPath);	
}
 

//Change '\'to'/', cause windows use'\' while linux use '/'. So that we need to Unify one kind of symbol.
void FormatDirectorys( LPSTR lpszDirectorys )
{
	if( lpszDirectorys!= NULL )
	{
		int i=0;

		while( lpszDirectorys[ i ] !=  _T('\0') ) 
		{
			if( lpszDirectorys[ i ] == _T('/') ) 
			{   
				lpszDirectorys[ i ] = _T('\\');			
			}

			i++;
		}
	}	
}

//unzip
DWORD UnZipToDirectory( LPCSTR lpszZipPathName, LPCSTR lpszDestDirectory)
{ 
	DWORD dwError = -1;
    	ZIPENTRY ze; 
	HZIP hz = NULL ;
	CHAR szOldDir[ MAX_PATH ] = _T("") ;
    QString dir = QDir::currentPath();

//The file name will be evaluated by the these sentences to determine if it is the right form.
    do
    {
	    if ( lpszZipPathName == NULL || lpszDestDirectory == NULL )
	    {  		
		    break;
	    }
	    if( strlen( lpszZipPathName ) ==0 || strlen( lpszDestDirectory ) == 0 )	
	    {		
		    break;
	    }	
	    if( !CreateDirectorys( lpszDestDirectory ) )
	    {
		    break;
	    }    
    	
//set the current working directory.
        strcpy(szOldDir,dir.toStdString().c_str());			
	    QDir::setCurrent(lpszDestDirectory ) ;    
    	
//evaluate the file will be opened or not, if not, will return to the start of the function.
	    hz = OpenZip( (void*)lpszZipPathName, 0, ZIP_FILENAME ) ;
	    if ( hz == NULL )
	    {
		    break;
	    }
    		
//get the zip file list file.
	    GetZipItem( hz, -1, &ze ) ;
    	
	    unsigned nItems = ze.index; 	
	    for ( int i = 0; i < nItems; i++ )
	    { 
		    dwError = GetZipItem( hz, i, &ze ); 
		    if ( dwError != ZR_OK )
		    {
			    break;
		    }
		    if( ze.attr & FILE_ATTRIBUTE_DIRECTORY)
		    {
			    CHAR szDestDir[ MAX_PATH ] = _T("") ;
    			
			    FormatDirectorys( ze.name) ;
    			
			    sprintf( szDestDir, _T("%s\\%s"), lpszDestDirectory, ze.name ) ;
    			
			    if( !CreateDirectorys( szDestDir ) )
			    {
				    break;
			    }   
			    continue ;
		    }
    		
		    dwError = UnzipItem( hz, i, ze.name, 0, ZIP_FILENAME );
		    if( dwError != ZR_OK )
		    {   		
                break;
		    }
	    }    
    }while(0);

	if( hz != NULL  ) 
	{
		CloseZip( hz );
	}	
    QDir::setCurrent( szOldDir ) ;	
	
	return dwError ; 
}
