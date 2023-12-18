#include "student.h"
#include "ui_student.h"

Student::Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
}

Student::~Student()
{
    delete ui;
}

void Student::on_pushButton_4_clicked()
{
    QApplication::quit();
}


void Student::on_pushButton_2_clicked()
{
   // hide();
    examPanel = new Exam(this);
    examPanel->set_timer(ui->timeEdit->time());
    examPanel->set_db(db);
    examPanel->set_ui();
    examPanel->show();

    connect(examPanel,&Exam::hide_this,this,&Student::show_this);
}


void Student::on_pushButton_clicked()
{
    file_name = QFileDialog::getOpenFileName(this,"Open database file","D://bsuir//Kursach//Kursuck2//qt//KurSuck//");


    db.set_Db(file_name);
    ui->textBrowser->setText(db.get_test_info());

}

