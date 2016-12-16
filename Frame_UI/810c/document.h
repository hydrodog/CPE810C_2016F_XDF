#ifndef DOCUMENT_HH__
#define DOCUMENT_HH__

#include <list>
#include <page.h>
class Document
{
private:
    std::list<Page> m_pageList;//Contain a list of Page
public:
    Document();
    std::list<Page> pageList(){return m_pageList;}
};

#endif // DOCUMENT_H
