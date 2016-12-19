#include "twodgraphics.h"

/**
 @author: Seito Ryu  18/11/16
*/
 //constructor
twoDGraphics::twoDGraphics(std::string operFilPath, std::string operFileName, std::vector<Shape> shpLst){
  operFilPath = operFilPath;
  operFileName = operFileName;
  shpLst = shpLst;
  //setOpterDic(opterTrie);
}
//read all operators from given file, set into a trie
void twoDGraphics::setOpterDic(OperatorDicTrie& opterTrie){
  std::ifstream opterFile(operFilPath + operFileName, std::ios_base::in);
  if(!opterFile){
    throw ExceptionTwoDG("Function: setOpterDic, string:" + operFilPath + operFileName + ". Couldn't open file!" + "\n");
      return;
  }
  std::string opter;
  try{
    while(std::getline(opterFile, opter)){
      if(opter != ""){
        opterTrie.addOptor(opter);
      }
    }
  }catch(std::exception &e){
    throw ExceptionTwoDG("Function: readEachLineFromPdf, string:" + opter + ". " + e.what() + "\n");
    return;
  }
}
//get all shape objects, saved in vector
void twoDGraphics::setShape(std::string curOpter, std::vector<double> curOpnds){
  //operator is not in the trie, if curOpter is nothing or is not in operator list, terminate and discard all information
#if 0
  if(!opterTrie.isOptor(curOpter)){
    return;
  }
#endif
  //create a new shape object
  Shape newShape;
  newShape.setOpter(curOpter);
  //there is no operand regarding to this operator
  if(curOpnds.size() == 0){
    shpLst.push_back(newShape);
    return;
  }
  try{
    newShape.setOpnds(curOpnds);
  }catch(ExceptionTwoDG d){
    throw d.getCng();
    return;
  }catch(std::exception &e){
    throw ExceptionTwoDG("Function: setShape, string:\n");
    return;
  }
  //add one line into shape object
  shpLst.push_back(newShape);
}
//get all shape objects, saved in vector
const std::vector<Shape>& twoDGraphics::getAllShape() const {
  return shpLst;
}
