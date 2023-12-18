#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "User.h"
#include "unregistered.h"
#include "new_exam.h"
#include "edit_exam.h"
#include "edit_profiles.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void unreg_close(){
         delete unreg;
    }
    void edit_ex_close(){
         delete edit_ex;
    }
    void edit_prof_close(){
         delete edit_prof;
    }
    void exam_close(){
         delete exam;
    }

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Unregistered *unreg;
    new_exam *exam;
    edit_exam *edit_ex;
    edit_profiles *edit_prof;

    Ui::Admin *ui;
};

#endif // ADMIN_H
