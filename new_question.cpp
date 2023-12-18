#include "new_question.h"
#include "ui_new_question.h"

new_question::new_question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_question)
{
    ui->setupUi(this);
}

new_question::~new_question()
{
    delete ui;
}

void new_question::on_pushButton_clicked()
{
    std::vector<QString> options;
    QString temp;
    QString question = ui->textEdit->toPlainText();
    int correct = ui->comboBox->currentIndex()+1;
    int options_count = ui->comboBox_2->currentIndex()+1;

    temp = ui->lineEdit1->text();
    options.push_back(temp);
    temp = ui->lineEdit2->text();
    options.push_back(temp);
    temp = ui->lineEdit3->text();
    options.push_back(temp);
    temp = ui->lineEdit4->text();
    options.push_back(temp);
    temp = ui->lineEdit5->text();
    options.push_back(temp);
    temp = ui->lineEdit6->text();
    options.push_back(temp);

    db.add_record(options_count,correct,question,options);


    this->questions--;
    if(this->questions == 0){
        hide_this();
        qDebug() << "HIDE THIS";
    }else{

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit3->clear();
    ui->lineEdit2->clear();
    ui->lineEdit5->clear();
    ui->lineEdit1->clear();
ui->lineEdit4->clear();
ui->lineEdit6->clear();
ui->textEdit->clear();
    }
}

