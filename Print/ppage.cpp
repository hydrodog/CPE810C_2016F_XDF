#include "ppage.h"
#include "includes.hh"

ppage::ppage(Page *page_in)
{
    page=page_in;

}

void ppage::print()
{
    std::list<Frame> frame_list=page->frameList();
    for (vector<int>::iterator i = frame_list.begin(); i !=frame_list.end(); i++)
    {
        pframe frame(&frame_list[i]);
        frame.draw();
    }

}

