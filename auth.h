#ifndef AUTH_H
#define AUTH_H

#include <QMainWindow>
#include <QTimer>

#include "admin.h"
#include "student.h"
#include "exam.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Auth; }
QT_END_NAMESPACE

class Auth : public QMainWindow
{
    Q_OBJECT

public:
    Auth(QWidget *parent = nullptr);
    ~Auth();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public slots:
    void updateDateTime();

private:
    Ui::Auth *ui;
    QTimer *timer;

    Exam *examPanel;
    Admin *adminPanel;
    Student *studentPanel;
};
#endif // AUTH_H
