#include "border.h"
#include<iostream>
using namespace std;
Border::Border(int height, int width):m_leftEdge(width/10),m_rightEdge(width/10),m_topEdge(height/10),m_downEdge(height/10)
{}

void Border::clear(){
    m_leftEdge=0;
    m_rightEdge=0;
    m_topEdge=0;
    m_downEdge=0;
}

