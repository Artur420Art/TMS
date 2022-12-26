#include "tms.h"
#include "ui_tms.h"
#include <fstream>
#include "mainpage.h"
#include "login.h"
TMS::TMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TMS)
{
    this->init();
    fetch();
    ui->setupUi(this);
    first = new Login();
    second = new MainPage();
    connect(first, &Login::first_window, this, &TMS::show);
    connect(second, &MainPage::second_window, this, &TMS::show);

}

TMS::~TMS()
{

    delete ui;
}

void TMS::fetch()
{
        fs.open("/Users/aa/Desktop/TmsProj/user.txt");
        if (!fs.is_open())
        {
            std::runtime_error("Failed to open DataBase/user.txt file");
        }

        std::string str;
        std::string spliter = " :}";
        std::string line;
        std::streampos m_value;
        std::vector<std::string> m_vec;

        while (!fs.eof())
        {
            getline(fs, str);
            auto m_vec = m_help->parser(str, spliter);
            m_value = fs.tellg();
            Userinf* tmp_obj = new Userinf();
            if (static_cast<bool>(m_keywords[m_vec[0]]))
            {
                m_read_pos[tmp_obj] = m_value;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->id = line;


                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->name = line;


                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->surname = line;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->email = line;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->password = line;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->status = std::stoi(line);

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->position = line;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->phone_number = line;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                m_help->line_cutter(line);
                tmp_obj->age = line;
            }
        }
        fs.close();
}
bool TMS::check_user()
{
        for (auto it : m_read_pos)
        {
            if (it.first->password == ui->email_2->text().toStdString() && it.first->name == ui->username->text().toStdString())
            {
                now_us = it.first;
                return true;
            }
        }
        return false;

}
void TMS::init()
{
        m_keywords["id"] = keywords::ID;
        m_keywords["{"] = keywords::SKOB;
        m_keywords["name"] = keywords::NAME;
        m_keywords["surname"] = keywords::SURNAME;
        m_keywords["email"] = keywords::EMAIL;
        m_keywords["password"] = keywords::PASSWORD;
        m_keywords["position"] = keywords::POSITION;
        m_keywords["number"] = keywords::PHONE_NUMBER;
        m_keywords["age"] = keywords::AGE;
}

void TMS::on_pushButton_2_clicked()
{
    fetch();
    if (ui->username->text().isEmpty() && ui->email_2->text().isEmpty())
    {
        ui->username->setStyleSheet("border:1px solid red;");
        ui->email_2->setStyleSheet("border:1px solid red;");
    }

    else if(ui->username->text().isEmpty() && ui->email_2->text().size() > 0) {
            ui->email_2->setStyleSheet("");
            ui->username->setStyleSheet("border:1px solid red;");
    }
    else if (ui->email_2->text().isEmpty() && ui->username->text().size() > 0)
    {
        ui->username->setStyleSheet("");
        ui->email_2->setStyleSheet("border:1px solid red;");
    }

    if(!check_user() && ui->username->text().size() > 0 &&  ui->email_2->text().size() > 0)
    {
        ui->username->setStyleSheet("");
        ui->email_2->setStyleSheet("");
        QMessageBox message;
        message.setStyleSheet("border:1px solid red;");
        message.critical(0, "Error!", "Wrong Username or Password");
        message.setFixedSize(600, 300);
    }
    if (check_user())
    {
        second->show();
        this->close();
    }

}


void TMS::on_pushButton_clicked()
{
    first->show();
    this->close();
}

