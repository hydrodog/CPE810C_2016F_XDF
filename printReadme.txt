This is Print team's readme
@Fan Yang @Zejian Zhou(zzhou12@stevens.edu)

--------------------How to print?-------------------------------------------------------

3 steps to print out

Step1: Include x_Print.hh

Step2: Create a Print instance, the constructor of this calss needs 2 arguments.

       Print(int startPage, int endPage);

Step3: Call the method "process". This method requires no argument.

Example:

       Print docu(18,30);//I wanna print page 18~ page 30
       docu.process();//Here we go!

------------------Structure-----------------------------------------------------------
//Main class, handle the whole document
Class: Print
Method: Process();//This method is used to handle the whole document, uses 'for' loop to print from start page to end page

//Page Handler
Class: PPage
Method: process();//This method is used to handle each page, uses 'for' loop to print from the 1st frame to the last frame

//Frame Handler
Class: PFrame

//Text Handler
Class: PText

//Image Handler
Class: PImage

//2d graphic Handler
Class: P2dgraphic
