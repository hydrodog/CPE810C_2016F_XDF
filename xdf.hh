/* File name: XDF.hh
 * Description: This class is designed to catch the XDF document and process the document
 * Author: Fan Yang, Zejian Zhou
 */

#ifndef XDF_HH
#define XDF_HH

#include <string>
#include <iostream>
#include <fstream>

class Print
{
private:
    int p_pageNumber;//total page number

public:
    Print(int startPage, int endPage);//TODO: remind frame team to give us total page number
    void process();//process and distribute


};


#endif // XDF_HH
