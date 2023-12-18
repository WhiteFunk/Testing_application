#ifndef STUDENT_H
#define STUDENT_H

#include "Exam.h"

#include <QDialog>
#include <QFileDialog>
#include <QString>

#include "exam_db_manager.h"

namespace Ui {
class Student;
}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void show_this(){
        show();
        delete examPanel;
    }
private:
    Ui::Student *ui;
    Exam *examPanel;

    exam_db_manager db;
    QString file_name;


};

#endif // STUDENT_H
