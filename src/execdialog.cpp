#include "execdialog.h"
#include "ui_execdialog.h"

execDialog::execDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::execDialog)
{
    ui->setupUi(this);
}

execDialog::~execDialog()
{
    delete ui;
}
