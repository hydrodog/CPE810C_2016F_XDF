#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "posinputdialog.h"

#include <QInputDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar *menuBar = this->menuBar();

    QMenu* fileMenu = menuBar->addMenu("Image");
    QAction* resetPicture = fileMenu->addAction("Reset Image");
    QAction* importPicture = fileMenu->addAction("Import Image");
    QAction* exportPicture = fileMenu->addAction("Export Image");
    QAction* rotatePicture = fileMenu->addAction("Rotate Image");
    QAction* scalePicture = fileMenu->addAction("Scale Image");
    QAction* setWidthHeight = fileMenu->addAction("Set Image Height And Width");

    connect(resetPicture, SIGNAL(triggered()), SLOT(resetImage()));
    connect(importPicture, SIGNAL(triggered()), SLOT(insertImage()));
    connect(exportPicture, SIGNAL(triggered()), SLOT(exportImage()));
    connect(rotatePicture, SIGNAL(triggered()), SLOT(rotateImage()));
    connect(scalePicture, SIGNAL(triggered()), SLOT(scaleImage()));
    connect(setWidthHeight, SIGNAL(triggered()), SLOT(setWidthHeight()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetImage()
{
    ui->frame->resetImage();
}

void MainWindow::insertImage()
{
    QString path = QFileDialog::getOpenFileName(this, "import image", "",
                                                     "JPG FILE(*.jpg *.jpeg);;PNG FILE(*.png);;TIFF FILE(*.tiff);;GIF FILE(*.gif)");
    if(!path.isEmpty())
    {
        QPoint pos;
        PosInputDialog dialog(this);
        connect(&dialog, &PosInputDialog::setPostion, this, [&pos](int x, int y){
            pos.setX(x);
            pos.setY(y);
        });
        dialog.exec();

        ui->frame->insertImage(path, pos);
    }
}

void MainWindow::exportImage()
{
    QString imageName = QFileDialog::getSaveFileName(this, "export image", "",
                                                     "PNG FILE(*.png);;JPG FILE(*.jpg *.jpeg);;PNG FILE(*.tiff);;PNG FILE(*.gif)");
    if(!imageName.isEmpty())
    {
        ui->frame->exportImage(imageName);
    }
}

void MainWindow::setWidthHeight()
{
    InputDialog dialog(this);
    connect(&dialog, &InputDialog::setWidthHeight, this, [this](int w, int h){
        ui->frame->setWidthHeight(w, h);
    });
    dialog.exec();
}

void MainWindow::scaleImage()
{
    float value = QInputDialog::getDouble(this, "input", "Please Enter Scale Value :", 0, 0, 5, 1);
    ui->frame->scaleImage(value);
}

void MainWindow::rotateImage()
{
    float value = QInputDialog::getDouble(this, "input", "Please Enter Degree :", 0, -360, 360, 1);
    ui->frame->rotateImage(value);
}
