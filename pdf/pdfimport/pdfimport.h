/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Huang
 */
#ifndef PDFIMPORT_H__
#define PDFIMPORT_H__
#include <podofo/podofo.h>

#include "pdfimage.h"
#include "pdfgraphics.h"
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
    virtual void AddTextElement( double dCurPosX, double dCurPosY,
                        PdfFont* pCurFont, const PdfString & rString );
    virtual void addGraphicsOperation(std::string operatorName, \
                                      std::vector<double> operands) {}
private:
    //xDocument* xdoc;
    PdfMemDocument* pDocument;
    ofstream of;
    ifstream fileConfig;
    ImageExtractor imageextractor;

    class PdfObj {
    public:
        int numOperands;
    };
    typedef std::map<std::string, PdfObj> mapPdfObj_t;
    mapPdfObj_t mapPdfGraphicsObj;

#ifdef PDF_IMPORT_TEST_MODE
    unordered_set<string> Operator_set; // for test only
    unordered_set<string> Operator_set_not_handled; // for test only

#endif
};

#endif // PDFIMPORT_H__
