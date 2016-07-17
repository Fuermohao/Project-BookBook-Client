#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <form.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BookBook-Client");
    connect(ui->LoadButton,SIGNAL(clicked()),this,SLOT(loadSlot()));
    connect(ui->lineEdit_name,SIGNAL(returnPressed()),this,SLOT(loadSlot()));
    connect(ui->lineEdit_id,SIGNAL(returnPressed()),this,SLOT(loadSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSlot()
{
    if(ui->lineEdit_name->text()!=""&&ui->lineEdit_id->text()!="")
    {
        QFile *file=new QFile;
        file->setFileName(QDir::currentPath()+"//load.txt");
        file->open(QIODevice::WriteOnly);
        QTextStream out(file);
        out<<ui->lineEdit_id->text()+"\n"+ui->lineEdit_name->text();
        file->close();
        Form *w=new Form;
        w->show();
        this->close();
    }
    else
    {
        QMessageBox::information(this,"Error Message","请填写完整登录信息！");
    }
}
