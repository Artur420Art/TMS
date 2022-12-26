#include "usersett.h"
#include "ui_usersett.h"
#include "tms.h"
usersett::usersett(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usersett)
{
    ui->setupUi(this);
}

usersett::~usersett()
{
    delete ui;
}


void usersett::on_logut_clicked()
{
    this->close();
}


void usersett::on_user_upd_clicked()
{
    ui->logut->setStyleSheet("color:green;");
}


void usersett::on_user_delete_clicked()
{

}

