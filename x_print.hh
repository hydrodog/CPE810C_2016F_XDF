/* File name: XDF.hh
 * Description: This class is designed to catch the XDF document and process the document
 * Author: Fan Yang, Zejian Zhou
 */

#ifndef X_PRINT_HH
#define X_PRINT_HH

#include <string>
#include <iostream>


class Print
{
private:
    int p_totalPageNumber;//total page number
    int p_startPage;
    int p_endPage;
    int p_currentPageNumber;

public:
    Print(int startPage, int endPage);//TODO: remind frame team to give us total page number
    void process();//process and distribute


};


#endif // XDF_HH
