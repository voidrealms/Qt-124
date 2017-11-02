#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::makeChanges(QString item)
{
    item.append(" Bottles of beer on the wall");
    return item;
}

void Dialog::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    QStringList itemsBefore;
    itemsBefore << "One" << "Two" << "Three";
    ui->listWidget->addItems(itemsBefore);

    QStringList itemsAfter = QtConcurrent::blockingMapped(itemsBefore, &Dialog::makeChanges);

    ui->listWidget_2->addItems(itemsAfter);


}
