#include "border.h"
#include<iostream>
using namespace std;
Border::Border(int height=800, int width=600):m_leftEdge(width/10),m_rightEdge(width/10),m_topEdge(height/10),m_downEdge(height/10)
{}

void Border::clear(){
}
