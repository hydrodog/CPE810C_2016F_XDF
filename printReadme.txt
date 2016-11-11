This is Print team's readme
@Fan Yang @Zejian Zhou(zzhou12@stevens.edu)

--------------------How to print?-------------------------------------------------------

Just call our dialog,that's all.

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



TODO: Print preview