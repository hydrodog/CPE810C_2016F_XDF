/*
 * Author: Zhuo Chen, Yingting Huang
 */
#ifndef PDFGRAPHICS_H__
#define PDFGRAPHICS_H__

#include <stack>
#include <vector>
#include <QPen>
#include <QtGui>

class PdfGState{
    PdfGState();


private:
    // The current transformation matrix. It maps positions from user coordinates
    // to device coordinates.
    std::vector<double> m_CTM;


    QPen m_qpen;
};

typedef std::stack<PdfGState> stackPdfGState_t;




#endif
