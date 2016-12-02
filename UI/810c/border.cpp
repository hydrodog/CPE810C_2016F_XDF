#include "border.h"
#include<iostream>
using namespace std;
Border::Border(int height, int width):m_leftEdge(width/20),m_rightEdge(width/20),m_topEdge(height/20),m_downEdge(height/20)
{}

void Border::clear(){
    m_leftEdge=60;
    m_rightEdge=60;
    m_topEdge=80;
    m_downEdge=80;
}

