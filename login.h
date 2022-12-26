#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <fstream>
#include "mainpage.h"
#include "helper.h"
#include <QMessageBox>

struct Userinf {
    std::string id = "NILL";
    std::string name = "NILL";
    std::string surname = "NILL";
    std::string email = "NILL";
    std::string password = "NILL";
    int status = 0;
    std::string position = "GUEST";
    std::string phone_number = "NILL";
    std::string age = "NILL";
};

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void fetch();
    void flush();
signals:
    void first_window();
private slots:
    void on_Sign_up_button_clicked();

private:
//    void flush();
    bool check_password(const std::string&);
    void init();
    bool valid_email(const std::string&);
    bool check_email(const std::string&);
    Helper* m_help;
    Ui::Login *ui;
    std::fstream fs;
    Userinf* m_user;
    MainPage* m_main;
    std::map<size_t, Userinf> m_userdata;
    std::map<Userinf*, std::streampos> m_read_pos;
    enum class keywords { ID = 100, NAME = 1, SURNAME, EMAIL, POSITION, PHONE_NUMBER, AGE, SKOB };
    std::map<std::string, keywords> m_keywords;
};
#endif // LOGIN_H
