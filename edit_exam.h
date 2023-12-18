#ifndef EDIT_EXAM_H
#define EDIT_EXAM_H

#include <QDialog>

#include "exam_db_manager.h"


#include <QFileDialog>
#include <QString>

#include "new_question.h"
#include "view_exam.h"

namespace Ui {
class edit_exam;
}

class edit_exam : public QDialog
{
    Q_OBJECT

public:
    explicit edit_exam(QWidget *parent = nullptr);
    ~edit_exam();

    void set_db(){
        file_name = QFileDialog::getOpenFileName(this,"Open database file","D://bsuir//Kursach//Kursuck2//qt//KurSuck//");
        db.set_Db(file_name);
    }


signals:
    void hide_this();

private slots:
    void show_this(){
        qDebug()<<"Delete";
        delete question_panel;
        qDebug()<<"Delete";
    }
    void remove_view(){
        qDebug()<<"Delete";
        delete view_ex;
        qDebug()<<"Delete";
    }

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:



    new_question *question_panel;
    view_exam *view_ex;

    Ui::edit_exam *ui;
    exam_db_manager db;
    QString file_name;
};

#endif // EDIT_EXAM_H
