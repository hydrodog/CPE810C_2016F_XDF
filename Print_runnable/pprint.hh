/*This is the main process class, It can procss print and distribute different objects
 * Author: @Zejian Zhou(Github:JayZejianZhou) @Fan Yang(Github:fyang14)
 * Edited at 13/10,2016
 */




#ifndef PPRINT_HH
#define PPRINT_HH

#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <includes.hh>
//test
class PPrint
{
private:
    int totalPageNum;
    int startPageNum;
    int endPageNum;
    bool isReverse;
    int isOdd;// 0 normal, 1 odd pages, 2 even pages @Zejian
    bool isPDF;//flag, if the user wanna print out as PDF


public:
    PPrint();
    void PProcess();//process the print
    void setTotalPageNum(int num);
    void setStartPageNum(int num);
    void setEndPageNum(int num);
    void setIsReverse(bool num);
    void setIsOdd(int num);
    void setIsPDF(bool is);
    void print();//deal with specific print situation @Zejian

};

#endif // PPRINT_HH
