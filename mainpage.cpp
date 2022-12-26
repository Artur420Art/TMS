#include "mainpage.h"
#include "ui_mainpage.h"
#include "tms.h"
MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    third = new usersett();
    connect(third, &usersett::third_window, this, &MainPage::show);
}


MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_pushButton_13_clicked()
{

}


void MainPage::on_Settings_clicked()
{
    third->show();
}

