#ifndef UNREGISTERED_H
#define UNREGISTERED_H

#include <QDialog>

#include "User.h"

namespace Ui {
class Unregistered;
}

class Unregistered : public QDialog
{
    Q_OBJECT

public:
    explicit Unregistered(QWidget *parent = nullptr);
    ~Unregistered();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void on_close();

private:
    Ui::Unregistered *ui;

    std::vector<User> t;
    int current;

    void set_text();
};

#endif // UNREGISTERED_H
