/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Chen
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

    PdfImporter importer;
  

  if( argc != 2 )
  {
    print_help();
    exit( -1 );
  }

  pszInput  = argv[1];
    
  try {
      importer.Init( pszInput );
  } catch( PdfError & e ) {
      fprintf( stderr, "Error: An error %i ocurred during processing the pdf file.\n", e.GetError() );
      e.PrintErrorMsg();
      return e.GetError();
  }

  return 0;
}
