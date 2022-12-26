#ifndef CENTER_H
#define CENTER_H

#include <QWidget>

namespace Ui {
class center;
}

class center : public QWidget
{
    Q_OBJECT

public:
    explicit center(QWidget *parent = nullptr);
    ~center();
signals:
    void second_window();

private:
    Ui::center *ui;
};

#endif // CENTER_H
