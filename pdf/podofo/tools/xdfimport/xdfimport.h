/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Chen
 */
#ifndef XDFIMPORT_H__
#define XDFIMPORT_H__

#include <podofo.h>
#include "pdfgstate.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <map>
using namespace std;
using namespace PoDoFo;

#ifndef MAX_PATH
#define MAX_PATH 512
#endif // MAX_PATH

#define PDF_IMPORT_TEST_MODE

/** This class uses the PoDoFo lib to parse
 *  a PDF file and to write all text it finds
 *  in this PDF document to stdout.
 */
class PdfImporter {
private:
    ofstream of;
    ifstream fileConfig;

    class PdfObj {
    public:
        int numOperands;
    };
    typedef std::map<std::string, PdfObj> mapPdfObj_t;
    mapPdfObj_t mapPdfGraphicsObj;

#ifdef PDF_IMPORT_TEST_MODE
    unordered_set<string> Operator_set; // for coding testing only
    unordered_set<string> Operator_set_not_handled; // for coding testing only
#endif
public:
    PdfImporter();
    virtual ~PdfImporter();
    
    void Init( const char* pszInput );
    
private:
    void loadFileConfig();

    /** Extract all text from the given page
     *
     *  \param pDocument the owning document
     *  \param pPage extract the text of this page.
     */
    void ImportPage( PdfMemDocument* pDocument, PdfPage* pPage );
    
    /** Adds a text string to a list which can be sorted by
     *  position on the page later, so that the whole structure
     *  of the text including formatting can be reconstructed.
     *
     *  \param dCurPosX x position of the text
     *  \param dCurPosY y position of the text
     *  \param pCurFont font of the text
     *  \param rString the actual string
     */
    void AddTextElement( double dCurPosX, double dCurPosY,
                        PdfFont* pCurFont, const PdfString & rString );
};

#endif // XDFIMPORT_H__
