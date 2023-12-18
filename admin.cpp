#include "admin.h"
#include "ui_admin.h"

#include <QProcess>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    QApplication::quit();
}



void Admin::on_pushButton_2_clicked()
{
    unreg = new Unregistered;
    unreg->show();
    connect(unreg,&Unregistered::on_close,this,&Admin::unreg_close);
}


void Admin::on_pushButton_4_clicked()
{
    exam = new new_exam;
    exam->show();
    connect(exam,&new_exam::on_close,this,&Admin::exam_close);
}


void Admin::on_pushButton_6_clicked()
{
    edit_ex = new edit_exam;
    edit_ex->show();
    edit_ex->set_db();
    connect(edit_ex,&edit_exam::hide_this,this,&Admin::edit_ex_close);
}


void Admin::on_pushButton_5_clicked()
{
    edit_prof = new edit_profiles();
    edit_prof->show();
    connect(edit_prof,&edit_profiles::hide_this,this,&Admin::edit_prof_close);
}

