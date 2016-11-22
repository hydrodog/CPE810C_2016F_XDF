/*
 @purpose: store data of each 2dgraphics, each shape object is one print stream
 @author: Seito Ryu  17/11/16
 */
class Shape{
private:
    double curX;
    double curY;
    //TODO: variables below need to confirm with print team
    int pageNo;
    double pageBot;
    double pageLef;
    double pageWid;
    double pageHei;
    //variables below using for draw a shape
    char* opter;
    std::vector<double> opnds;
public:
    Shape(double curX = 0, double curY = 0, int pageNo = 0, double pageBot = 0, double pageLef = 0, double pageWid = 0,
          double pageHei = 0, char* opter = nullptr, std::vector<double> opnds = {}): curX(curX), curY(curY), pageNo(pageNo), pageBot(pageBot), pageLef(pageLef), pageWid(pageWid),
    pageHei(pageHei), opter(opter), opnds(opnds) {}
    ~Shape(){
        if(opter != nullptr){
            delete opter;
        }
    }
    //copy constructor
    Shape(const Shape& curShp){
        std::string tmpStr = curShp.opter;
        
        curX = curShp.curX;
        curY = curShp.curY;
        pageNo = curShp.pageNo;
        pageBot = curShp.pageBot;
        pageLef = curShp.pageLef;
        pageWid = curShp.pageWid;
        pageHei = curShp.pageHei;
        opter = new char[tmpStr.size() + 1];
        std::strcpy(opter, tmpStr.c_str());
        for(auto x: curShp.opnds){
            opnds.push_back(x);
        }
    }
    //add current operator into shape object
    void setOpter(const std::string& val){
        opter = new char[val.size() + 1];
        std::strcpy(opter, val.c_str());
    }
    //add all numbers for drawing into shape object
    void setOpnds(const std::vector<double>& val){
        for(auto x: val){
            opnds.push_back(x);
        }
    }
    //return shape object's operator
    //inline std::string getOpter() const{
    inline const char*  getOpter() const{
        return opter;
    }
    //return all numbers of the shape object
    inline const std::vector<double>& getOpnds() const{
        return opnds;
    }
    //virtual std::ostream& draw() = 0;
};