#ifndef TMS_H
#define TMS_H

#include <QMainWindow>
#include <fstream>
#include <iostream>
#include "mainpage.h"
#include "login.h"
#include "helper.h"
#include "usersett.h"
#include <unordered_map>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TMS; }
QT_END_NAMESPACE

class TMS : public QMainWindow
{
    Q_OBJECT

public:
    TMS(QWidget *parent = nullptr);
    ~TMS();
    void delete_user();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
       void fetch();
       void init();
       bool check_user();
private:
    Ui::TMS *ui;
    Helper* m_help;
    Login* first;
 public:
    MainPage* second;
private:
    std::fstream fs;
    Userinf* now_us;
    std::map<Userinf*, std::streampos> m_read_pos;
    enum class keywords { ID = 100, NAME = 1, SURNAME, EMAIL, PASSWORD, POSITION, PHONE_NUMBER, AGE, SKOB };
    std::unordered_map<std::string, keywords> m_keywords;


};

#endif // TMS_H
