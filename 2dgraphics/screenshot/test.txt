#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <string>
#include <fstream>
#include <vector>
#include <QPaintEvent>
#include <QPainter>
#include <QtSvg/QSvgRenderer>

using namespace std;

class Draw2DGraphics : public QWidget{
private:
    //source data file path
    string m_path;
    //source data file name
    string m_sourceFile;
    //store all source data in SVG format
    vector<string> allObjects;
    /**
        TODO:
        read source file and set all drawing objects to allObject variable
        assume each line in source file represents one object, data is stored by certain rules
        The rules of how to store drawing data will be decided in future
    */
    void setDrawingObjects(){}
public:
    //constructor
    Draw2DGraphics(){}
    /**
        in order to get source data, this method will be implemented by other class
    */
    static void setDataSource(const string& path_, const string& sourceFile_){
      m_path = path_;
      m_sourceFile = sourceFile_;
    }
    /**
        set path of source data file
    */
    string getPath() const {return path;}
    /**
        set name of source data file
    */
    string getsourceFile() const {return sourceFile;}
    /**
        TODO:
        read from variable allObject and display them on mainwindow
    */
    virtual void paintEvent(QPaintEvent* event){
	  for(auto vector::iterator iter = allObjects.begin; iter != allObjects.end(); iter++){
	    display each object at certain position on to mainwindow(ostream)
      }
    }
}