/*file name: xdfFrame.hh
 * description: this class is used to recogonize frame of XDF file
 * Author: Fan Yang, Zejian Zhou*/

#ifndef XDFFRAME_HH
#define XDFFRAME_HH

class Frame{
private:
    int page;//save page number
    int upBoundry;
    int downBoundry;
    int leftBoundry;
    int rightBoundry;//one frame instance process one block data
    int framNumber=0;
public:
    Frame(char * posi);//the constructor should get the pointer which points to the beginning of fame datablock
    int getPage();//get current printing page number
    int getUpBoundry();
    int getDownBoundry();
    int getLeftBoundry();
    int getRightBoundry();//get 4 boundries
    int getFrameNumber();//get frame number
};

#endif // XDFFRAME_HH
