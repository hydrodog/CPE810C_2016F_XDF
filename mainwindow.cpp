#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"

#include <QDebug>
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
    if(!m_inputPath.isEmpty())
    {
         if(!m_orImage.load(m_inputPath))
         {
             qDebug() << "Input Error!";
             return;
         }
         ui->textEdit->clear();
         ui->textEdit->textCursor().insertImage(m_orImage);
    }
}

void MainWindow::insertImage()
{
    m_inputPath = QFileDialog::getOpenFileName(this, "import image", "",
                                                     "JPG FILE(*.jpg *.jpeg);;PNG FILE(*.png);;TIFF FILE(*.tiff);;GIF FILE(*.gif)");
    resetImage();
}

void MainWindow::exportImage()
{
    QString imageName = QFileDialog::getSaveFileName(this, "export image", "",
                                                     "PNG FILE(*.png);;JPG FILE(*.jpg *.jpeg);;PNG FILE(*.tiff);;PNG FILE(*.gif)");
    if(!imageName.isEmpty())
    {
        m_orImage.save(imageName);
    }
}

void MainWindow::setWidthHeight()
{
    InputDialog dialog(this);
    connect(&dialog, SIGNAL(setWidthHeight(int,int)), SLOT(setWidthHeight(int,int)));
    dialog.exec();
}

void MainWindow::setWidthHeight(int width, int height)
{
    ui->textEdit->clear();
    m_orImage = m_orImage.scaled(width, height);
    ui->textEdit->textCursor().insertImage(m_orImage);
}

void MainWindow::scaleImage()
{
    float value = QInputDialog::getDouble(this, "input", "Please Enter Scale Value :", 0, 0, 5, 1);

    m_orImage = m_orImage.scaled(m_orImage.width()*value, m_orImage.height()*value, Qt::KeepAspectRatio);
    ui->textEdit->clear();
    ui->textEdit->textCursor().insertImage(m_orImage);
}

void MainWindow::rotateImage()
{
    float degree = QInputDialog::getDouble(this, "input", "Please Enter Degree :", 0, -360, 360, 1);

    QMatrix rotate;
    m_orImage = m_orImage.transformed(rotate.rotate(degree), Qt::SmoothTransformation);
    ui->textEdit->clear();
    ui->textEdit->textCursor().insertImage(m_orImage);
}
