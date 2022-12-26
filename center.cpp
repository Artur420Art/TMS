#include "center.h"
#include "ui_center.h"

center::center(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::center)
{
    ui->setupUi(this);
}

center::~center()
{
    delete ui;
}
