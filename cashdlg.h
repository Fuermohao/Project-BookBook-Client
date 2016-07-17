#ifndef CASHDLG_H
#define CASHDLG_H

#include <QDialog>


namespace Ui {
class CashDlg;
}

class CashDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CashDlg(QWidget *parent = 0);
    ~CashDlg();

private:
    Ui::CashDlg *ui;
private slots:
    //void CountSlot(int books);
};

#endif // CASHDLG_H
