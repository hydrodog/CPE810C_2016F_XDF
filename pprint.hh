/*This is the main process class, It can procss and distribute different objects
 * Author: @Zejian Zhou(Github:JayZejianZhou) @Fan Yang(Github:fyang14)
 * Edited at 11/10,2016
 */




#ifndef PPRINT_HH
#define PPRINT_HH

#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>

class PPrint
{
private:
    int totalPageNum;
    int startPageNum;
    int endPageNum;

public:
    PPrint(int total,int start,int end);
    void PProcess();//process the print

};

#endif // PPRINT_HH
