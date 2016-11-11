/** Nathalie Tran: commenting what she understands and asking design questions

  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QWidget>
#include <QFontDialog>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //sets up window size and title
    ui->setupUi(this);
    this->setWindowTitle("XDF project");
    this->resize(1300,800);

    /** sets up functions. adds to menu, adds to toolbar, connect buttons to functions, added common shortcuts
     * functions at bottom of code
     * TODO:
     * do we actually need all of them on the toolbar?
     * do we actually want a toolbar?
     */
    //file menu
    QMenu* filesMenu = ui->menuBar->addMenu("File");

    //new files
    QAction* action_New = filesMenu->addAction("New File");
    action_New->setShortcut(QKeySequence("Ctrl+N"));
    QAction* new1 = ui->mainToolBar->addAction("New");
    connect(action_New,SIGNAL(triggered()),this,SLOT(NewFile()));
    connect(new1,SIGNAL(triggered()),this,SLOT(NewFile()));

    //open files
    QAction* action_Open=filesMenu->addAction("Open Files");
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    QAction* open = ui->mainToolBar->addAction("Open");
    connect(action_Open,SIGNAL(triggered()),this,SLOT(OpenFile()));
    connect(open,SIGNAL(triggered()),this,SLOT(OpenFile()));

    //save files
    QAction* action_Save = filesMenu->addAction("Save Files");
    action_Save->setShortcut(QKeySequence("Ctrl+S"));
    QToolButton* SaveFiles = new QToolButton(this);
    SaveFiles->setText("Save");
    ui->mainToolBar->addWidget(SaveFiles);
    connect(action_Save,SIGNAL(triggered()),this,SLOT(SaveFile()));
    //do we not have a save file function? i can't find it

    //save as... exists in menu . does not do anything YET
    QAction* action_Saveas=filesMenu->addAction("Save as...");
    /**
     * @brief subMenuImport
     * Added a submenu as a stylized decision can be removed
     *  Includes PDF, ePub, Images
     * Learned that menu order of items is by order in the code
     */
    QMenu* subMenuImport = filesMenu->addMenu("Import");

    //import PDF
    QAction* action_importPDF=subMenuImport->addAction("PDF");
    connect(action_importPDF,SIGNAL(triggered()),this,SLOT(ImportPDF()));

    //import ePUB: exists in menu. does not do anything YET
    QAction* action_importEPUB=subMenuImport->addAction("ePUB");

    //import image
    QAction* action_importImage=subMenuImport->addAction("Image");
    connect(action_importImage,SIGNAL(triggered()),this,SLOT(ImportImage()));

    //print: exists in menu. does not do anything YET
    QAction* action_Print=filesMenu->addAction("Print");
    action_Print->setShortcut(QKeySequence("Ctrl+P"));

    //print review
    QAction* action_Review=filesMenu->addAction("Print Preview");
    QAction* review = ui->mainToolBar->addAction("Preview");
    connect(action_Review,SIGNAL(triggered()),this,SLOT(FileReview()));
    connect(review,SIGNAL(triggered()),this,SLOT(FileReview()));

    //quit
    QAction* action_Quit=filesMenu->addAction("Quit");
    connect(action_Quit,SIGNAL(triggered()),this,SLOT(quit1()));

/**
  Adds Edit Menu and Tools
  TODO: work with other teams to eventually get functions. we have no functions for any of these except setColor has a pop up box
  */

       //edit---Menu
       QMenu* editMenu = ui->menuBar->addMenu("edit");


       //font
       QAction* action_Font = editMenu->addAction("Font");
       connect(action_Font,SIGNAL(triggered()),this,SLOT(font()));


       //color
       QAction* action_Color = editMenu->addAction("Color");
       connect(action_Color,SIGNAL(triggered()),this,SLOT(SetColor()));


       //form
       QMenu* Form = editMenu->addMenu("Form");
       QAction* action_Left = Form->addAction("Left");
       QAction* action_center = Form->addAction("center");
       QAction* action_right = Form->addAction("right");



/**
  Adds a tool Menu with the 2D and 3D drawings
  Function currently brings up a popup
  */
       //tool---Menu
       QMenu* toolMenu = ui->menuBar->addMenu("Tool");


       //2D
       QAction* action_2D = toolMenu->addAction("2D");
       QAction* tool_2d = ui -> mainToolBar -> addAction("2D");
       connect(action_2D,SIGNAL(triggered()),this,SLOT(tool2D()));
       connect(tool_2d,SIGNAL(triggered()),this,SLOT(tool2D()));




       //3D
       QAction* action_3D = toolMenu->addAction("3D");
       QAction* tool3d = ui->mainToolBar->addAction("3D");
       connect(action_3D,SIGNAL(triggered()),this,SLOT(tool3D()));
       connect(tool3d,SIGNAL(triggered()),this,SLOT(tool3D()));

/**
  adds a help menu
  does nothing right now: does it need a function or what should the function be?
  maybe add a text doc to include what all the functions do as a summary
  */
       //help---Menu
       QMenu* helpMenu = ui->menuBar->addMenu("help");


       //about
       QAction* action_about=helpMenu->addAction("about");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::NewFile
 * makes a popup window when New File is selected
 * there is no fuction yet, just a pop up that the task worked
 */
void MainWindow::NewFile(){
   QMessageBox::about(this,"New File","There should be a new file function");
}

/**
 * @brief MainWindow::OpenFile
 * When Open is selected it does this function
 * opens box to choose .png, .jpg, .txt file
 * returns if no file is picked
 * returns file name of file picked. DOES NOT ACTUALLY OPEN FILE (YET)
 */
void MainWindow::OpenFile(){
   QString fileName = QFileDialog::getOpenFileName(this,"Open File","D:","picture(*.png *.jpg) ;; text(*.txt)");
   if (fileName==NULL){
       QMessageBox::about(this,"New File","No file was selected");
   }
   else if (fileName!=NULL){
       QMessageBox::about(this,"New File",fileName);
   }
}


void MainWindow::quit1(){
   int quit1 = QMessageBox::question(this,"Quit","Are you sure you want to quit?",QMessageBox::Yes,QMessageBox::No);
   if( quit1 == QMessageBox::Yes )
       close();
}


void MainWindow::font(){
   bool ok;
   QFont font=QFontDialog::getFont(&ok,this);
}


void MainWindow::FileReview(){
   QMessageBox::about(this,"File Preview","There should be a file Preview function.");
}


void MainWindow::tool2D(){
   QMessageBox::about(this,"2D","there should be a 2d function.");
}


void MainWindow::tool3D(){
   QMessageBox::about(this,"3D","there should be a 3D function");
}


void MainWindow::ImportPDF(){
   QString filePDF = QFileDialog::getOpenFileName(this,"Import PDF","D:","PDF(*.pdf)");


   if (filePDF==NULL){
       QMessageBox::about(this,"Import PDF","No file was selected");
   }
   else if (filePDF!=NULL){
       QMessageBox::about(this,"Import PDF",filePDF);
   }
}


void MainWindow::ImportImage(){
   QString fileimage = QFileDialog::getOpenFileName(this,"Import Image","D:","picture(*.png *.jpg)");


   if (fileimage==NULL){
       QMessageBox::about(this,"import image","No file was selected");
   }
   else if (fileimage!=NULL){
       QMessageBox::about(this,"import image",fileimage);
   }
}


void MainWindow::SetColor(){
   QColorDialog color(this);
   color.setOption(QColorDialog::ShowAlphaChannel);
   color.exec();
}
