/*
 * Author: Zhuo Chen, Yingting Huang
 */
#ifndef PDFIMAGE_H__
#define PDFIMAGE_H__


using namespace PoDoFo;

#ifndef MAX_PATH
#define MAX_PATH 512
#endif // MAX_PATH

/** This class uses the PoDoFo lib to parse 
 *  a PDF file and to write all images it finds
 *  in this PDF document to a given directory.
 */
class ImageExtractor {
 public:
    ImageExtractor();
    virtual ~ImageExtractor();

    /**
     * \param pnNum pointer to an integer were 
     *        the number of processed images can be stored
     *        or null if you do not want this information.
     */
    void Init( PdfMemDocument *document, int* pnNum = NULL );

    /**
     * \returns the number of succesfully extracted images
     */
    inline int GetNumImagesExtracted() const;

 private:
    /** Extracts the image form the given PdfObject
     *  which has to be an XObject with Subtype "Image"
     *  \param pObject a handle to a PDF object
     *  \param bJpeg if true extract as a jpeg, otherwise create a ppm
     *  \returns ErrOk on success
     */
    void ExtractImage( PoDoFo::PdfObject* pObject, bool bJpeg );

    /** This function checks wether a file with the 
     *  given filename does exist.
     *  \returns true if the file exists otherwise false
     */
    bool    FileExists( const char* pszFilename );

 private:
    char*        m_pszOutputDirectory;
    unsigned int m_nSuccess;
    unsigned int m_nCount;

    char         m_szBuffer[MAX_PATH];
};

inline int ImageExtractor::GetNumImagesExtracted() const
{
    return m_nSuccess;
}

#endif
