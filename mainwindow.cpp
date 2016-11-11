#include "image.h"
#include "ui_mainwindow.h"
#include <QTextImageFormat>
#include <QTextEdit>
#include <QFileDialog>
#include <QMenu>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* fileMenu = ui->menuBar->addMenu("Picture");

    QAction* import_picture = fileMenu->addAction("Import Image");
    QAction* set_height = fileMenu->addAction("Set Height");
    QAction* set_width = fileMenu->addAction("Set Width");
    connect(import_picture,SIGNAL(triggered()),this, SLOT (insertImage()));
    connect(set_height,SIGNAL(triggered()),this, SLOT (setHeight()));
    connect(set_width,SIGNAL(triggered()),this, SLOT (setWidth()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertImage(){
    imageName=QFileDialog::getOpenFileName(this,"import image","D:","image(*.png *.jpg)");
    format.setName(imageName);
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::setHeight(){
    bool ok;
    height=QInputDialog::getInt(this,"input","Please Enter Height :",0,0,1000,1,&ok);

    format.setHeight(height);
}

void MainWindow::setWidth(){
    bool ok;
    width=QInputDialog::getInt(this,"input","Please Enter Width :",0,0,1000,1,&ok);

    format.setWidth(width);
}
