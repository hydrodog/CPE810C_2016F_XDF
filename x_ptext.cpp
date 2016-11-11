#include <../x_PText.hh>

PText::PText(string name){
    fileName=name;
}

void PText::print(int x,int y){
    string test="Let's test the string";
    ofstream f;
    f.open(fileName);
    f<<'/'<<"Times-Roman findfont\n 20 scalefont\n setfont \n"<<x<<' '<<y<<' '<<"moveto\n"<<" ("<<test<<") show\n ";
}
