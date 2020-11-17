#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include "select.h"
#include <QFileDialog>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()  //按截屏键
{
   this->hide();
    QTimer::singleShot(300, this, SLOT(onDelayedCapture()));

}

void MainWindow::onDelayedCapture()
{
    QPixmap screen 	= QPixmap::grabWindow(QApplication::desktop()->winId());
    select dlg(screen,this);
    if(QDialog::Accepted==dlg.exec()){
         region = screen.copy(dlg.selectsquare);
         ui->selectedpicture->setPixmap(region);
    }
    this->showNormal();
}



void MainWindow::on_toolButton_2_clicked()//按保存键
{
    QString filename = QFileDialog::getSaveFileName(this,
        "Save Picture", "", "Image File(*.jpg)");
    region.save(filename);
}
