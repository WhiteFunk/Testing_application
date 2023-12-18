#include "edit_exam.h"
#include "ui_edit_exam.h"

edit_exam::edit_exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_exam)
{
    ui->setupUi(this);

}

edit_exam::~edit_exam()
{
    delete ui;
}

void edit_exam::on_pushButton_clicked()
{
    QString temp = ui->textEdit->toPlainText();
    db.update_info(temp);
}


void edit_exam::on_pushButton_4_clicked()
{
    hide();
}


void edit_exam::on_pushButton_3_clicked()
{
    QString temp = ui->textEdit->toPlainText();
    db.delete_question(temp);
    db.update_info(db.get_tasks_count()+1);
}


void edit_exam::on_pushButton_2_clicked()
{
    question_panel = new new_question;
    question_panel->set_db(db);
    question_panel->set_questions(1);
    question_panel->show();

    db.update_info(db.get_tasks_count()+1);

    connect(question_panel,&new_question::hide_this,this,&edit_exam::show_this);
}


void edit_exam::on_pushButton_5_clicked()
{
    view_ex = new view_exam(this);
    view_ex->set_db(db);
    view_ex->set_ui();
    view_ex->show();

    connect(view_ex,&view_exam::hide_this,this,&edit_exam::remove_view);
}

