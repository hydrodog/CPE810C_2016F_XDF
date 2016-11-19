/**
    @author: Seito Ryu  17/11/16
    @modified: ...
*/
/*
    Receive 2dgraphics data when reading pdf file
    Set all related 2dgraphics data into class(es) constructor(s)
    using draw method(s) to print
 */

#include <iostream>
#include <vector>

#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

/*
    base class of 2dgraphics
    @author: Seito Ryu  17/11/16
 */
class shape{
private:
    double curX;
    double curY;
    //TODO: variables below need to confirm with print team
    int pageNo;
    double pageBot;
    double pageLef;
    double pageWid;
    double pageHei;
    
    char* opter;
    std::vector<double> *opnds;
public:
    shape(double curX = 0, double curY = 0, int pageNo = 0, double pageBot = 0, double pageLef = 0, double pageWid = 0,
          double pageHei = 0): curX(curX), curY(curY), pageNo(pageNo), pageBot(pageBot),
            pageLef(pageLef), pageWid(pageWid), pageHei(pageHei) {
                opter = nullptr;
                opnds = nullptr;
    }
    ~shape(){
        if(opter != nullptr){
            delete opter;
        }
        if(opnds != nullptr){
            delete opnds;
        }
    }
    virtual std::ostream& draw() = 0;
};


void split(const std::string &s, char delim, std::vector<double> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(std::atof(item.c_str()));
    }
}
std::vector<double> split(const std::string &s, char delim) {
    std::vector<double> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
    std::ifstream samplePdfData("sample.txt", std::ios_base::in);
    
    if(!samplePdfData){
        std::cerr << "There's an error when opening 'sample.txt'" << "\n";
        exit(-1);
    }
    
    //TODO:pdf team should use code below to test their function
    //get the content of each line when reading a pdf file
    std::string strLine;
    std::string opterLine;
    while(getline(samplePdfData, strLine)){
        //get second character: operator
        opterLine = strLine.substr(1,1);
        //if 3rd character is (, then delete the first three charater '[(_'
        //and delete the last two character ')]'
        //if 3rd character is NOT (, finish
        if(strLine.substr(2,1) == "("){
            strLine = strLine.substr(3, strLine.length() - 5);
        }else{
            std::cout << opterLine << "-";
            std::cout << "\n";
            continue;
        }
        //get all numbers deliminated by comma
        std::vector<double> vecLine = split(strLine, ',');
        
        std::cout << opterLine << "-";
        //set data from read pdf
        for(auto iteLine = vecLine.begin(); iteLine != vecLine.end(); iteLine++){
            std::cout << *iteLine << ",";
        }
        std::cout << "\n";
    }

}















