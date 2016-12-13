#include "common.h"
#include "ZHead.h"
#include "XUnzip.h"
#include <string>
#include <list>
using namespace std;

 
/*
功能：根据目录路径生成对应的目录
*/ 
BOOL CreateDirectorys( LPCSTR lpszPath )
{    
    return QDir().mkpath(lpszPath);	
}
 

//文件目录格式化
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
 
DWORD UnZipToDirectory( LPCSTR lpszZipPathName, LPCSTR lpszDestDirectory)
{ 
	DWORD dwError = -1;
    ZIPENTRY ze; 
	HZIP hz = NULL ;
	CHAR szOldDir[ MAX_PATH ] = _T("") ;
    QString dir = QDir::currentPath();

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
    	    
        strcpy(szOldDir,dir.toStdString().c_str());			
	    QDir::setCurrent(lpszDestDirectory ) ;    
    	
	    hz = OpenZip( (void*)lpszZipPathName, 0, ZIP_FILENAME ) ;
	    if ( hz == NULL )
	    {
		    break;
	    }
    			
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
