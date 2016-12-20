#ifndef TWO_DGRAPHICS_HH__
#define TWO_DGRAPHICS_HH__

#include "operatordictrie.h"
#include "shape.h"
#include "exceptiontwodg.h"
#include <string>
#include <vector>
#include <fstream>
#include <QPointF>
#include <QString>



class textBox
{
private:
    QPointF m_topLeftPosition;
    QString m_text;
public:
    textBox(QPointF topLeftPosition, std::string text);
    QPointF topLeftPosition() {return m_topLeftPosition;}
    QString text() {return m_text;}
};
typedef std::vector<textBox> textBoxes_t;


/*
 @author: Seito Ryu  18/11/16
 @Purpose: set raw data by pdf team
 */
class twoDGraphics{
private:
  std::string operFilPath;
  std::string operFileName;
  std::vector<Shape> shpLst;
  textBoxes_t m_textBoxes;
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

  void addTextBox(textBox txtBox);
  textBoxes_t* pTextBoxes(){ return &m_textBoxes;}
};



#endif
