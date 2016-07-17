#include "cashdlg.h"
#include "ui_cashdlg.h"


CashDlg::CashDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("支付");
}

CashDlg::~CashDlg()
{
    delete ui;
}


