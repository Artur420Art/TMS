#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "usersett.h"
namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();
signals:
    void second_window();
private slots:
    void on_pushButton_13_clicked();

    void on_Settings_clicked();

private:
    Ui::MainPage *ui;
    usersett* third;
};

#endif // MAINPAGE_H
