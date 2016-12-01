#ifndef PPAGE_H
#define PPAGE_H
#include "includes.hh"

class ppage
{
private:
    Page * page;
public:
    ppage(Page * page_in );
    void print();
};

#endif // PPAGE_H
