#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "dialog.h"
#include "cashdlg.h"4

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;
    QString id;
    Dialog *dlg;
    CashDlg *w;
signals:
    void count(int books);
private slots:
    void OpenFileSlot();
    void ChooseSlot();
    void DelSlot();
    void SaveSlot();
    void ChangeUser();
    void LoadSlot();
    void ShowID(QString message);
    void CashSlot();

};

#endif // FORM_H
