#include "view_exam.h"
#include "ui_view_exam.h"

#include <QRadioButton>
#include <QTextBrowser>
#include <QScrollArea>
#include <QVBoxLayout>

view_exam::view_exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_exam)
{
    ui->setupUi(this);
}

view_exam::~view_exam()
{
    delete ui;
}

void view_exam::set_ui()
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
    qDebug()<<questions;
    tasks= db.get_tasks();
    for(int i= 0;i<questions;i++){
        groupBoxLayout->addWidget(createFirstExclusiveGroup(i+1,tasks[i].get_options_number(),tasks[i].get_options(),tasks[i].get_question()));
    }
}

void view_exam::on_pushButton_3_clicked()
{
    this->hide_this();
}

QGroupBox *view_exam::createFirstExclusiveGroup(int number_of_question, int number_of_options, std::vector<std::string> options, std::string question)
{

    qDebug()<<"START";
    QGroupBox *groupBox = new QGroupBox(tr(qPrintable("Question "+QString::number(number_of_question))));
    QVBoxLayout *vbox = new QVBoxLayout;
    QTextBrowser *text = new QTextBrowser();

    qDebug()<<"END CREATION"
                ""
                "";
    text->setMinimumSize(600,200);
    text->resize(600,200);
    text->setText(QString::fromStdString(question));
    vbox->addWidget(text);
qDebug()<<"QRADIOBUTTON";
    for(int i=0; i<number_of_options;i++){
        QRadioButton *radio1 = new QRadioButton(tr(qPrintable(QString::fromStdString(options[i]))));
        radio1->setMinimumSize(600,30);
        vbox->addWidget(radio1);
    }

    vbox->addStretch(1);
    groupBox->setLayout(vbox);
qDebug()<<"RETURN";
    return groupBox;
}

