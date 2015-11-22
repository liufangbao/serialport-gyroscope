#ifndef EXECDIALOG_H
#define EXECDIALOG_H

#include <QDialog>

namespace Ui {
class execDialog;
}

class execDialog : public QDialog
{
    Q_OBJECT

public:
    explicit execDialog(QWidget *parent = 0);
    ~execDialog();

private:
    Ui::execDialog *ui;
};

#endif // EXECDIALOG_H
