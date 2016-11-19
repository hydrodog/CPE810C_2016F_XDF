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
    exception for reading operators
    @author: Seito Ryu  18/11/16
 */
class isNotLowCaseChar{
private:
    char valChr;
public:
    isNotLowCaseChar(char val): valChr(val) {}
    friend std::ostream& operator << (std::ostream& s, const isNotLowCaseChar& b){
        return s << "Error: " << b.valChr << " is not low case character and is not in operators dictionary!" << "\n";
    }
};
/*
    all operators set into a trie
    @author: Seito Ryu  18/11/16
 */
class OperatorDicTrie{
private:
    class Node{
    public:
        Node* next[26];
        bool isOptor[26];
        Node(){
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
                isOptor[i] = false;
            }
        }
    };
    Node* root;
public:
    OperatorDicTrie():root(new Node) {}
    void addOptor(const std::string& s){
        unsigned long length = s.length();
        Node* curNode = root;
        int offset = 0;
        for(int i = 0; i < length; i++){
            char curChar = s[i];
            if(curChar < 'a' || curChar > 'z'){
                throw isNotLowCaseChar(curChar);
            }
            offset = curChar - 'a';
            if(i == (length - 1)){
                curNode->isOptor[offset] = true;
            }else{
                if(! curNode->next[offset]){
                    curNode->next[offset] = new Node;
                }
                curNode = curNode->next[offset];
            }
        }
    }
    bool isOptor(const std::string& s){
        bool resultBl = false;
        unsigned long length = s.length();
        Node* curNode = root;
        int offset = 0;
        for(int i = 0; i < length; i++){
            char curChar = s[i];
            if(curChar < 'a' || curChar > 'z'){
                return false;
            }
            offset = curChar - 'a';
            if(i == (length - 1) && curNode->isOptor[offset])
                return true;
            if(curNode->next[offset]){
                curNode = curNode->next[offset];
            }else{
                return false;
            }
        }
        return resultBl;
    }
};

/*
    store data of each 2dgraphics
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
    
    char * opter;
    std::vector<double> opnds;
public:
    shape(std::string val, double curX = 0, double curY = 0, int pageNo = 0, double pageBot = 0, double pageLef = 0, double pageWid = 0,
          double pageHei = 0, std::vector<double> opnds = {}): curX(curX), curY(curY), pageNo(pageNo), pageBot(pageBot), pageLef(pageLef), pageWid(pageWid),
        pageHei(pageHei), opnds(opnds) {
            opter = new char[val.size() + 1];
            std::memcmp(opter, val.c_str(), val.size() + 1);
        }
    ~shape(){
        if(opter != nullptr){
            delete opter;
        }
    }
    shape(const shape& curShp){
        std::string tmpStr = curShp.opter;
        
        curX = curShp.curX;
        curY = curShp.curY;
        pageNo = curShp.pageNo;
        pageBot = curShp.pageBot;
        pageLef = curShp.pageLef;
        pageWid = curShp.pageWid;
        pageHei = curShp.pageHei;
        opter = new char[tmpStr.size() + 1];
        std::memcmp(opter, tmpStr.c_str(), tmpStr.size() + 1);
        for(auto ite = curShp.opnds.begin(); ite != curShp.opnds.end(); ite++){
            opnds.push_back(*ite);
        }
    }
/*
    void setOpter(const std::string& val){
        opter = new char[val.size() + 1];
        std::memcmp(opter, val.c_str(), val.size() + 1);
    }
*/
    void setOpnds(std::vector<double> val){
        for(std::vector<double>::iterator ite = val.begin(); ite != val.end(); ite++){
            opnds.push_back(*ite);
        }
    }
    std::string getOpter() const{
        return opter;
    }
    std::vector<double> getOpnds() const{
        return opnds;
    }
    //virtual std::ostream& draw() = 0;
};
/*
    @author: Seito Ryu  18/11/16
 */
class Ecp2dGpc{
private:
    std::string errCnt;
public:
    Ecp2dGpc(std::string val): errCnt(val) {}
    friend std::ostream& operator << (std::ostream& s, const Ecp2dGpc& e){
        return s << "Error: " << e.errCnt << ". When processing 2dgraphics!" << "\n";
    }
    std::string getCng() const{
        return errCnt;
    }
};
/*
    TODO: operDicPath, operFileName, opndsStaSgn, opndsEndSgn, opterStaSgn, opterEndSgn should be set by pdf team

    pdf team(set pdf data) and print team(display on screen) use this class
    @author: Seito Ryu  18/11/16
 */
class twoDGraphics{
private:
    std::string operFilPath;
    std::string operFileName;
    std::string pdfFilPath;
    std::string pdfFileName;
    char opterStaSgn;
    char opterEndSgn;
    char opndsStaSgn;
    char opndsEndSgn;
    char intervSgn;
    std::vector<shape> shpLst;
    
    void split(const std::string &s, char delim, std::vector<double> &elems) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        try{
            while (getline(ss, item, delim)) {
                elems.push_back(std::atof(item.c_str()));
            }
        //TODO: std::exception? how to get exact exception message
        }catch(std::exception err){
            throw Ecp2dGpc("Function: split, string:" + s + ". " + err.what() + "\n");
        }
    }
    std::vector<double> split(const std::string &s, char delim) {
        std::vector<double> elems;
        split(s, delim, elems);
        return elems;
    }
public:
    twoDGraphics(std::string operFilPath, std::string operFileName, std::string pdfFilPath, std::string pdfFileName, char opterStaSgn, char opterEndSgn, char opndsStaSgn, char opndsEndSgn, char intervSgn, std::vector<shape> shpLst = {}): operFilPath(operFilPath), operFileName(operFileName), pdfFilPath(pdfFilPath), pdfFileName(pdfFileName), opterStaSgn(opterStaSgn), opterEndSgn(opterEndSgn), opndsStaSgn(opndsStaSgn), opndsEndSgn(opndsEndSgn), intervSgn(intervSgn), shpLst(shpLst){}
    ~twoDGraphics(){
    }
    
    void setOpterDic(OperatorDicTrie& opterTrie){
        std::ifstream opterFile(operFilPath + operFileName, std::ios_base::in);
        if(!opterFile){
            throw Ecp2dGpc("Function: setOpterDic, string:" + operFilPath + operFileName + ". Couldn't open file!" + "\n");
            return;
        }
        //add each word into trie
        std::string opter;
        try{
            while(std::getline(opterFile, opter)){
                if(opter != ""){
                    opterTrie.addOptor(opter);
                }
            }
        }catch(const char * s){
            throw Ecp2dGpc("Function: setOpterDic, string:" + opter + ". Couldn't read this operator!" + "\n");
        }
    }
    
    void readEachLineFromPdf(std::string& strLine, OperatorDicTrie& opterTrie){
        
        if(strLine[0] != opterStaSgn){
            return;
        }
        int posOpterSta = -1;
        int posOpterEnd = -1;
        int posOpndsSta = -1;
        int posOpndsEnd = -1;
        
        for(int i = 0; i < strLine.size(); i++){
            if(strLine[i] == opterStaSgn){
                posOpterSta = i;
            }else if(strLine[i] == opterEndSgn){
                posOpterEnd = i;
            }else if(strLine[i] == opndsStaSgn){
                posOpndsSta = i;
            }else if(strLine[i] == opndsEndSgn){
                posOpndsEnd = i;
            }
        }
        if(posOpterSta == -1
           || posOpterEnd == -1
           || posOpndsSta == -1
           || posOpndsEnd == -1){
            return;
            //throw Ecp2dGpc("Function: readEachLineFromPdf, string:" + strLine + ". Couldn't identify all borders of operators or operends!");
        }
        
        std::string curOpter = strLine.substr(posOpterSta + 1, posOpndsSta - posOpterSta - 1);
        if(!opterTrie.isOptor(curOpter)){
            return;
        }
        shape newShape(curOpter);
        /*
        shape newShape;
        newShape.setOpter(curOpter);
        */
        strLine = strLine.substr(posOpndsSta + 1, posOpndsEnd - posOpndsSta - 1);
        try{
            newShape.setOpnds(split(strLine, intervSgn));
        }catch(Ecp2dGpc d){
            throw d.getCng();
            return;
        }catch(const char * s){
            throw Ecp2dGpc("Function: readEachLineFromPdf, string:" + strLine + ". " + s + "\n");
            return;
        }
        
        shpLst.push_back(newShape);
    }

    void readFileFromPdf(){
        std::ifstream pdfData(pdfFilPath + pdfFileName, std::ios_base::in);
        if(!pdfData){
            throw Ecp2dGpc("Function: readFileFromPdf, string:" + pdfFilPath + pdfFileName + ". Couldn't open file!" + "\n");
            return;
        }
        
        OperatorDicTrie opterTrie;
        setOpterDic(opterTrie);

        std::string strLine;
        while(getline(pdfData, strLine)){

            readEachLineFromPdf(strLine, opterTrie);
        }
    }
    
    std::vector<shape> getAllShape() const {
        return shpLst;
    }
    /*
    friend std::ostream& operator << (std::ostream& s, const twoDGraphics& twoDGph){
        s << "Operator dictionary file:" << "\n";
        s << twoDGph.operFilPath << twoDGph.operFilPath << "\n";
        s << "Pdf data file:" << "\n";
        s<< twoDGph.pdfFilPath << twoDGph.pdfFileName << "\n";
        
        for(auto ite = twoDGph.shpLst.begin(); ite != twoDGph.shpLst.end(); ite++){
            s << "Operator is " << ite->getOpter() << "\n";
            std::vector<double> allOpnds = ite->getOpnds();
            for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); iteOpnds++){
                s << "-" << *iteOpnds;
            }
        }
        
        return s;
    }
    */
};


int main(){
    twoDGraphics* twoDGph = new twoDGraphics("/Users/SeitoRyu/Documents/", "operator.txt", "/Users/SeitoRyu/Documents/", "sample.txt", '[', ']', '(', ')', ',');
    
    twoDGph->readFileFromPdf();
    
    //std::cout << twoDGph;
    int i = 0;
    for(auto ite = twoDGph->getAllShape().begin(); ite != twoDGph->getAllShape().end(); ite++){
        std::cout << i++ << "\t";
        std::cout << "Operator is " << ite->getOpter() << "\n";
        std::vector<double> allOpnds = ite->getOpnds();
        for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); iteOpnds++){
            std::cout << "-" << *iteOpnds;
        }
    }
    
    /*
     twoDGraphics(std::string operFilPath, std::string operFileName, std::string pdfFilPath, std::string pdfFileName, char opterStaSgn, char opterEndSgn, char opndsStaSgn, char opndsEndSgn, char intervSgn, std::vector<shape> shpLst = {}): operFilPath(operFilPath), operFileName(operFileName), pdfFilPath(pdfFilPath), pdfFileName(pdfFileName), opterStaSgn(opterStaSgn), opterEndSgn(opterEndSgn), opndsStaSgn(opndsStaSgn), opndsEndSgn(opndsEndSgn), intervSgn(intervSgn), shpLst(shpLst){}
     */
    
    
    /*
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
    }*/

}















