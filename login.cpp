#include "login.h"
#include "ui_login.h"
#include <fstream>
#include <locale>
#include <map>
#include <iostream>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    init();
    fetch();
    m_user = new Userinf();
    ui->setupUi(this);
}

Login::~Login()
{
//    flush();
    delete ui;
}
void Login::fetch()
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
void Login::init()
{
        m_keywords["id"] = keywords::ID;
        m_keywords["{"] = keywords::SKOB;
        m_keywords["name"] = keywords::NAME;
        m_keywords["surname"] = keywords::SURNAME;
        m_keywords["email"] = keywords::EMAIL;
        m_keywords["position"] = keywords::POSITION;
        m_keywords["number"] = keywords::PHONE_NUMBER;
        m_keywords["age"] = keywords::AGE;
}

void Login::flush()
{
    fs.open("/Users/aa/Desktop/TmsProj/user.txt", std::ios::app);
            if (!fs.is_open())
            {
                   std::cout << "aaa";
            }

    static int counter = 1;
    if (!m_read_pos.empty())
    {
        for (auto it : m_read_pos)
             {

                 fs << "{\n"
                 << std::setw(10) <<         "id:" << counter++ << "\n"
                 << std::setw(13) <<         "Name: " << it.first->name << "\n"
                 << std::setw(16) <<         "Surname: " << it.first->surname << "\n"
                 << std::setw(14) <<         "Email: " << it.first->email << "\n"
                 << std::setw(14) <<         "Password: " << it.first->password << "\n"
                 << std::setw(15) <<         "Status: " << it.first->status << "\n"
                 << std::setw(17) <<         "Position: " << it.first->position << "\n"
                 << std::setw(21) <<         "Phone Number: " << it.first->phone_number << "\n"
                 << std::setw(12) <<         "Age: " << it.first->age << "\n"
                 << "}\n" << std::endl;
             }
    }
   if (!m_userdata.empty())
   {
        for (auto it : m_userdata)
            {
                fs << "{\n"
                << std::setw(10) <<         "id:" << counter++ << "\n"
                << std::setw(13) <<         "Name: " << it.second.name << "\n"
                << std::setw(16) <<         "Surname: " << it.second.surname << "\n"
                << std::setw(14) <<         "Email: " << it.second.email << "\n"
                << std::setw(17) <<         "Password: " << it.second.password << "\n"
                << std::setw(15) <<         "Status: " << it.second.status << "\n"
                << std::setw(17) <<         "Position: " << it.second.position << "\n"
                << std::setw(21) <<         "Phone Number: " << it.second.phone_number << "\n"
                << std::setw(12) <<         "Age: " << it.second.age << "\n"
                << "}\n" << std::endl;
            }
}
    fs.close();
    }

bool Login::check_email(const std::string& email)
{

    if (!m_read_pos.empty())
    {

        for (auto it : m_read_pos)
        {
            if(it.first->status == -1 && it.first->email == email) { return true; }
            if (it.first->email == email)
            {
                return false;
            }
        }
    }
    if (!m_userdata.empty())
    {
        for (auto it : m_userdata)
        {
            if(it.second.status == -1 && it.second.email == email) { return true; }
            if (it.second.email == email)
            {
                return false;
            }
        }
    }
    return true;
}
bool Login::valid_email(const std::string& rhs)
{
    if (rhs.empty()) { return false; }
    std::size_t at_signe_ind = rhs.find('@');
    if (at_signe_ind == std::string::npos) { return false; }
    std::string to_check = rhs.substr(at_signe_ind, rhs.size() - at_signe_ind);
    int size = at_signe_ind;
    for (int i = 0; i < size; ++i)
    {
        if (!((rhs[i] >= 'a' && rhs[i] <= 'z') || (rhs[i] >= 'A' && rhs[i] <= 'Z') || (rhs[i] == 46) || (rhs[i] == 95) || (rhs[i] >= '0' && rhs[i] <= '9')))
        {
            return false;
        }
    }
    if ((to_check == "@gmail.com") || (to_check == "@mail.ru" || to_check == "@inbox.ru"))
    {
        return true;
    }
    return false;
}

bool Login::check_password(const std::string& password)
{
    for (auto it : m_read_pos)
    {
        if (it.first->password == password)
        {
            return true;
        }
    }
    return false;
}
void Login::on_Sign_up_button_clicked()
{
    if (ui->User_reg->text().isEmpty() && ui->email_reg->text().isEmpty() && ui->Age_reg->text().isEmpty())
    {
        ui->User_reg->setStyleSheet("border:1px solid red;");
        ui->email_reg->setStyleSheet("border:1px solid red;");
        ui->Age_reg->setStyleSheet("border:1px solid red;");
    }
     else if (ui->User_reg->text().isEmpty() && ui->email_reg->text().size() > 0 && ui->Age_reg->text().isEmpty()) {
            ui->email_reg->setStyleSheet("");
            ui->User_reg->setStyleSheet("border:1px solid red;");
            ui->Age_reg->setStyleSheet("border:1px solid red;");
    }
    else if (ui->email_reg->text().isEmpty() && ui->User_reg->text().size() > 0 && ui->Age_reg->text().size() > 0)
    {
        ui->Age_reg->setStyleSheet("");
        ui->User_reg->setStyleSheet("");
        ui->email_reg->setStyleSheet("border:1px solid red;");
    }
    else if (ui->User_reg->text().size() > 0 && ui->email_reg->text().size() > 0 && ui->Age_reg->text().isEmpty())
    {
        ui->User_reg->setStyleSheet("");
        ui->email_reg->setStyleSheet("");
        ui->Age_reg->setStyleSheet("border:1px solid red;");
    }
    else if (ui->User_reg->text().size() > 0 && ui->email_reg->text().isEmpty() && ui->Age_reg->text().isEmpty())
    {
        ui->User_reg->setStyleSheet("");
        ui->Age_reg->setStyleSheet("border:1px solid red;");
        ui->email_reg->setStyleSheet("border:1px solid red;");
    }
    else if (ui->email_reg->text().size() > 0 && ui->Age_reg->text().size() > 0 && ui->User_reg->text().isEmpty())
    {
        ui->email_reg->setStyleSheet("");
        ui->Age_reg->setStyleSheet("");
        ui->User_reg->setStyleSheet("border: 1px solid red;");
    }
    else if (ui->email_reg->text().isEmpty() && ui->Age_reg->text().size() > 0  && ui->User_reg->text().isEmpty())
    {
        ui->email_reg->setStyleSheet("border:1px solid red");
        ui->Age_reg->setStyleSheet("");
        ui->User_reg->setStyleSheet("border: 1px solid red;");
    }

    else if (!valid_email(ui->email_reg->text().toStdString()))
    {
        QMessageBox mes;
        mes.critical(0, "Error", "Invalid email address");
        mes.setFixedSize(600, 300);
    }

    else if (!check_email(ui->email_reg->text().toStdString()))
    {
             QMessageBox mes;
             mes.critical(0, "Error", "Email was already used");
             mes.setFixedSize(600, 300);
    }
    else if(check_email(ui->email_reg->text().toStdString()))
    {
                ui->email_reg->setStyleSheet("");
                m_user->name = ui->User_reg->text().toStdString();
                m_user->surname = ui->Surname_reg->text().toStdString();
                m_user->email = ui->email_reg->text().toStdString();
                m_user->password = ui->Age_reg->text().toStdString();
                m_user->position = ui->pos_reg->text().toStdString();
                m_user->phone_number = ui->phone_reg->text().toStdString();
                m_user->age = ui->age_reg->text().toStdString();

                size_t id = 1;
                m_userdata.insert(std::make_pair(id, *m_user));
                ++id;
                flush();

                this->close();
                emit first_window();
    }
}
