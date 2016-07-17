#include "form.h"
#include "ui_form.h"
#include "dialog.h"
#include "QFile"
#include "QFileDialog"
#include "QDir"
#include "QTextStream"
#include "cashdlg.h"
#include "QMessageBox"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("BookBook-Client");
    LoadSlot();
    dlg=new Dialog(this);
    connect(ui->OpenButton,SIGNAL(clicked()),this,SLOT(OpenFileSlot()));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ChooseSlot()));
    connect(ui->listWidget_2,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(DelSlot()));
    connect(ui->SavaButton,SIGNAL(clicked()),this,SLOT(SaveSlot()));
    connect(ui->ChangeButton,SIGNAL(clicked()),this,SLOT(ChangeUser()));
    connect(dlg,SIGNAL(dlgreturn(QString)),this,SLOT(ShowID(QString)));
    connect(ui->CashButton,SIGNAL(clicked()),this,SLOT(CashSlot()));
    //connect(ui->CashButton,SIGNAL(clicked()),w,SLOT()
}

Form::~Form()
{
    delete ui;
}

void Form::OpenFileSlot()
{
    QFile *file=new QFile;
    QString fileName=QFileDialog::getOpenFileName(this,"打开");
    file->setFileName(fileName);
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(file);
    while(!in.atEnd())
    {
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(in.readLine());
        ui->listWidget->addItem(item);
    }
    file->close();
}

void Form::ChooseSlot()
{
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(ui->listWidget->currentItem()->text());
    ui->listWidget_2->addItem(item);
}

void Form::DelSlot()
{
    QListWidgetItem *item=ui->listWidget_2->currentItem();
    delete item;
}

void Form::SaveSlot()
{
    int count=ui->listWidget_2->count();
    QString list=id+"\n";
    for(int i=0;i<count;i++)
    {
        list+=ui->listWidget_2->item(i)->text()+"\n";
    }
    QFile *file=new QFile;
    QString fileName=QFileDialog::getSaveFileName(this,"保存");
    file->setFileName(fileName);
    file->open(QIODevice::WriteOnly);
    QTextStream in(file);
    in<<list;
    file->close();
}

void Form::ChangeUser()
{
   dlg->show();
}

void Form::LoadSlot()
{
    QFile *file=new QFile;
    file->setFileName(QDir::currentPath()+"//load.txt");
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(file);
    id=in.readAll();
    ui->label_id->setText(id.split("\n").at(0));
    file->close();
}

void Form::ShowID(QString message)
{
    ui->label_id->setText(message);
}

void Form::CashSlot()
{
    int books=ui->listWidget_2->count();
    QMessageBox::information(this,"应缴金额",ui->label_id->text()+"应缴预定金为"+QString::number(10*books));
    w=new CashDlg;
    w->show();
}
