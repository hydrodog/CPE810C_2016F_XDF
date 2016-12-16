#ifndef CONTENT_HH__
#define CONTENT_HH__
/*This head file "content" is written by the Frame and Text group,we share it with the
 * print group!This class "Content" can store a part of the same style text and their font.
 * It can also deal with the message which sent by other groups.
 */
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include<QString>
#include<QFont>
#include<Qcolor>
using namespace std;
class Content{
private:

    QFont m_font;//QFont to set font
    QColor m_color;//Qcolor to set color
    std::wstring m_str;  //main text
    int k;         //length of the text
    int n=0;       //Quantity of the line change marks
    int changelinepos[20]={0};   //which position the text changes its line
    map<int,string> alignment;   //alignment ways
public:
    void readInMessage(std::wstring a);     //read in text sent by other groups
    void readInFont(std::string a);         //read in message of font sent by other groups
    QFont font(){return m_font;}            //get the font stored in the object
    QColor color(){return m_color;}         //get the color of words in the object
    std::wstring str(){return m_str;}       //get the text stored in the object
    void str(std::wstring str){m_str=str;}  //another way to get the text in the object
    void font(QFont f){m_font=f;}           //set the font in the object
    void color(QColor c){m_color=c;}        //set the color in the object
    void readInalignment(int *n,int *m);    //read in the alignment sent by other group
    map<int,string> exportalignment();      //get the alignment stored in the object
    int getlength();                        //get the length of the text in the object
    int* getlinechange();                   //get the line change position in the object
    int getlineamount();                    //get the quantity of the line change marks
    QString getQString();                   //make the text in the object become qstring and get it
};

#endif // CONTENT_H
