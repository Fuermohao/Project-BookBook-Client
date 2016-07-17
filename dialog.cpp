#include "dialog.h"
#include "ui_dialog.h"
#include "QFile"
#include "QDir"
#include "QTextStream"
#include "QMessageBox"
#include "form.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("BookBook-Client");
    connect(ui->LoadButton,SIGNAL(clicked()),this,SLOT(loadSlot()));
    //connect(ui->LoadButton,SIGNAL(clicked()),QObject::Form,SLOT(Form::LoadSlot()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadSlot()
{
    if(ui->lineEdit_name->text()!=""&&ui->lineEdit_id->text()!="")
    {
        QFile *file=new QFile;
        file->setFileName(QDir::currentPath()+"//load.txt");
        file->open(QIODevice::WriteOnly);
        QTextStream out(file);
        out<<ui->lineEdit_id->text()+"\n"+ui->lineEdit_name->text();
        file->close();
        QString message=ui->lineEdit_id->text();
        emit dlgreturn(message);
        this->close();
    }
    else
    {
        QMessageBox::information(this,"Error Message","请填写完整登录信息！");
    }
}
