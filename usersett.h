#ifndef USERSETT_H
#define USERSETT_H

#include <QMainWindow>

namespace Ui {
class usersett;
}

class usersett : public QMainWindow
{
    Q_OBJECT

public:
    explicit usersett(QWidget *parent = nullptr);
    ~usersett();

private:
    Ui::usersett *ui;
signals:
    void third_window();
private slots:

    void on_logut_clicked();
    void on_user_upd_clicked();
    void on_user_delete_clicked();
};

#endif // USERSETT_H
