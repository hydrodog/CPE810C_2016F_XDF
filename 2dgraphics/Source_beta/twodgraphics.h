#ifndef TWO_DGRAPHICS_HH__
#define TWO_DGRAPHICS_HH__

#include "operatordictrie.h"
#include "shape.h"
#include "exceptiontwodg.h"
#include <string>
#include <vector>
#include <fstream>

/*
 @author: Seito Ryu  18/11/16
 @Purpose: set raw data by pdf team
 */
class twoDGraphics{
private:
  std::string operFilPath;
  std::string operFileName;
  std::vector<Shape> shpLst;
  OperatorDicTrie opterTrie;
public:
  twoDGraphics(std::string operFilPath, std::string operFileName, std::vector<Shape> shpLst = {});//: operFilPath(operFilPath), operFileName(operFileName), shpLst(shpLst){}
  ~twoDGraphics(){}
  //read all operators from given file, set into a trie
  void setOpterDic(OperatorDicTrie& opterTrie);
  //get all shape objects, saved in vector
  void setShape(std::string curOpter, std::vector<double> curOpnds);
  //get all shape objects, saved in vector
  const std::vector<Shape>& getAllShape() const;
};
#endif
