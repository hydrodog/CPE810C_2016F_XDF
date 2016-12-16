/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Huang
*/

#include "xdfimport.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

#ifdef _HAVE_CONFIG
#include <config.h>
#endif // _HAVE_CONFIG

void print_help()
{
  cout << "Usage: ./xdfimport [inputfile]\n\n";
  cout << "\nPoDoFo Version:" << PODOFO_VERSION_STRING << "\n\n";
}

int main( int argc, char* argv[] )
{
    char*    pszInput;

  

    if( argc != 2 )
    {
        print_help();
        exit( -1 );
    }

    pszInput  = argv[1];
    
    try {
        PdfImporter importer;
        importer.Init( pszInput );
        //importer.getXDoc();
    } catch( PdfError & e ) {
        fprintf( stderr, "Error: An error %i ocurred during processing the pdf file.\n", e.GetError() );
        e.PrintErrorMsg();
        return e.GetError();
    } catch(char const * pszErrorMessage) {
        std::cout << "Error occurred while importing a pdf file:" << pszErrorMessage << endl;
        return 1;
    } catch(string & sErrorMessage) {
        std::cout << "Error occurred while importing a pdf file:" << sErrorMessage << endl;
        return 1;
    }


    return 0;
}
