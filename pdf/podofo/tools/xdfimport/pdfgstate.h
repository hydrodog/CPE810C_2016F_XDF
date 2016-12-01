/*
 * Author: Zhuo Chen, Yingting Chen
 */
#ifndef PDFGSTATE_H__
#define PDFGSTATE_H__

#include <stack>
#include <vector>
#include <QPen>


class PdfGState{
    PdfGState();


private:
    std::vector<double> m_CTM;
    QPen pen;
};

typedef std::stack<PdfGState> stackPdfGState_t;



#endif
