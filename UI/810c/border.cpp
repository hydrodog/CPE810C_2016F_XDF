#include "border.h"
#include<iostream>
using namespace std;
Border::Border(double height, double width):leftEdge(width/10),rightEdge(width/10),topEdge(height/10),downEdge(height/10)
{}
void Border::Setcolor(int i){
    color=i;
}

void Border::clear(){
}
