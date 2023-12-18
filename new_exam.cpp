#include "new_exam.h"
#include "ui_new_exam.h"

new_exam::new_exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_exam)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
}

new_exam::~new_exam()
{
    delete ui;
}

void new_exam::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    int questions = ui->spinBox->value();
    QString info = ui->textEdit->toPlainText();

    db.set_Db(name+".db");
    db.add_record(questions,info);

    question_panel = new new_question;
    question_panel->set_db(db);
    question_panel->set_questions(questions);
    question_panel->show();

    connect(question_panel,&new_question::hide_this,this,&new_exam::show_this);
}

