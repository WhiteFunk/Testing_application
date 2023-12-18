#include "exam.h"
#include "ui_exam.h"

#include <QRadioButton>
#include <QTextBrowser>
#include <QScrollArea>
#include <QVBoxLayout>

#include <QMessageBox>

Exam::Exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);


   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTime()));
   timer->start(1000);


}

Exam::~Exam()
{
    delete ui;


}

void Exam::set_ui()
{
    QScrollArea *scrollArea = new QScrollArea();
    QVBoxLayout *groupBoxLayout = new QVBoxLayout();
    QWidget *widget = new QWidget();
    ui->questionsPanel->addWidget(scrollArea);
    scrollArea->setWidget(widget);
    widget->setLayout(groupBoxLayout);

    scrollArea->setFixedSize(600,500);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    questions = db.get_tasks_count();
    try {
        tasks= db.get_tasks();
        for(int i= 0;i<questions;i++){

            groupBoxLayout->addWidget(createFirstExclusiveGroup(
                i+1,tasks[i].get_options_number(),
                tasks[i].get_options(),tasks[i].get_question()));
        }
    } catch (std::bad_alloc const&) {
        qDebug()<< "Bad allocation";
    }


}

void Exam::updateDateTime()
{
   time = time.addSecs(-1);
    if(time == QTime(0,0,0,0)){
        int right_answers = 0;


        for(int i =0;i<questions;i++){
            int checked = 0;
            qDebug()<<tasks[i].get_options_number();
            for(int j = 0;j<tasks[i].get_options_number();j++){
                if(buttons[i][j]->isChecked()){
                    checked = j+1;
                    break;
                }
            }
            qDebug()<<checked << "          " <<tasks[i].get_correct_answer();
            if(checked == tasks[i].get_correct_answer()){
                right_answers++;
            }
        }

        QMessageBox msgBox;
        msgBox.setText("Testing is over");
        msgBox.setInformativeText("Right answers: " + QString::number(right_answers) + "\nTime to end:" + time.toString());
        msgBox.exec();
        qDebug()<<right_answers;
        this->hide_this();
   }
   QString formattedTime = time.toString();
   ui->label_4->setText(formattedTime);
}

QGroupBox *Exam::createFirstExclusiveGroup(int number_of_question,int number_of_options, std::vector<std::string> options, std::string question)
{
//   qDebug() << "NEW CALL FUNCTION";
//   for(auto i: options){
//        qDebug() << i;
//   }

    QGroupBox *groupBox = new QGroupBox(//tr(qPrintable("Question "+QString::number(number_of_question)))
        );
    QVBoxLayout *vbox = new QVBoxLayout;
    QTextBrowser *text = new QTextBrowser();
    text->setMinimumSize(600,200);
    text->resize(600,200);
    text->setText(QString::fromStdString(question));
    vbox->addWidget(text);
    std::vector<QRadioButton*>temp;
    buttons.push_back(temp);

    for(int i=0; i<number_of_options;i++){
        QRadioButton *radio1 = new QRadioButton(tr(qPrintable(QString::fromStdString(options[i]))));
        buttons[number_of_question-1].push_back(radio1);
        radio1->setMinimumSize(600,30);
        vbox->addWidget(radio1);
    }

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}



void Exam::on_pushButton_3_clicked()
{
    int right_answers = 0;


    for(int i =0;i<questions;i++){
        int checked = 0;
        qDebug()<<tasks[i].get_options_number();
        for(int j = 0;j<tasks[i].get_options_number();j++){
            if(buttons[i][j]->isChecked()){
                checked = j+1;
                break;
            }
        }
        qDebug()<<checked << "          " <<tasks[i].get_correct_answer();
        if(checked == tasks[i].get_correct_answer()){
            right_answers++;
        }
    }

    QMessageBox msgBox;
    msgBox.setText("Testing is over");
    msgBox.setInformativeText("Right answers: " + QString::number(right_answers) + "\nTime to end:" + time.toString());
    msgBox.exec();
    qDebug()<<right_answers;
    this->hide_this();
}


void Exam::on_pushButton_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

