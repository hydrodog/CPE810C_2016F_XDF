Final Project Report #1: Initial design
X/Print team
Fan Yang, Zejian Zhou


Class: scanner //Interpret the text flow to various objects according to the grammer of postscript
Constructor: scanner(string fileName);//constructor should bring in the XDF file.
Method: print();// distribute blank space, comment, numbers, string, char, frame, image and 2dGraphics by flags.


Classes used for different objects
Class: blankSpace   //process blank space or other uses
Constructor: blankSpace(char * posi1);//constructor should bring in the position of that blank 
Methods: transform();// give the specifc definitions or functions in postscript for blank spaces based on various situations 
                print();// print out this blank space based on the transformed data


Class: numbers //process and display numbers 
Constructor: numbers(double * posi);//constructor should bring in the position of those numbers 
Methods: readIn();// read in numbers from xdf file 
                print();// print out numbers in ps file in right position




Class: stringData //process and display strings
Constructor: stringData (char * posi1);//constructor should bring in the position of that tringData 
Methods: readIn();// read in string from xdf file
                print();// print out string based on read-in data




Class: charSymbol //process and display symbols
Constructor: charSymbol (char * posi1);//constructor should bring in the position of that    //charSymbol 
Methods: readIn();// read in symbols from xdf file 
                print();// print out symbols based on read-in data




Class: image// process and display images
Constructor: image(char * posi1);//constructor should bring in the position of that   image 
Methods: transform();// give the specifc definitions or functions in postscript for images based on various situations 
                print();// print out this image based on the transformed data




Class: 2dGraphic// process and draw 2d graphics like lines and circles
Constructor: 2dGraphic(char * posi1);//constructor should bring in the position of that    //2dGraphic 
Methods: transform();// give the specifc definitions or functions in postscript for 2d graphics based on various situations 
                print();// print out this 2d graphics based on the transformed data
                drawLine(int x1, int y1, int x2, int y2);//print out a line
                drawPoint(int x, int y);//print a point
                drawCircle(int x, int y, int r);// print a circle


Class: Frame//Get the frame of the XDF file
Constructor: Frame();
Methods: readFrame();//read in frame data
                int getUpBoundary();// return the coordinate of up boundary
                int getDownBoundary();// return the coordinate of down boundary
                int getLeftBoundary();// return the coordinate of left boundary
                int getRightBoundary();// return the coordinate of right boundary
                int getPage();// return the coordinate of page






   




