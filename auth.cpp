#include "auth.h"
#include "./ui_auth.h"

#include <QProcess>
#include <QDateTime>

#include <fstream>
#include <string>

#define  profiles_f std::string("profiles.txt")
#define  buff_f std::string("buffer.txt")
#define  cars_f std::string("cars.txt")
#define  undefined_f std::string("undefined.txt")

Auth::Auth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Auth)
{


    ui->setupUi(this);

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    ui->label_4->setText(formattedTime);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTime()));
    timer->start(1000);

}

Auth::~Auth()
{
    delete ui;
}


void Auth::on_pushButton_clicked()
{
    QApplication::quit();
}


void Auth::on_pushButton_2_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void Auth::updateDateTime()
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    ui->label_4->setText(formattedTime);
}


void Auth::on_pushButton_3_clicked()
{

//    hide();
//    examPanel = new Exam();
//    examPanel->show();



    QString un = ui->lineEdit_username->text();
    QString pw = ui->lineEdit_password->text();

    User t(un.toStdString(),pw.toStdString(),Role::undefined);

    User temp;

    std::ifstream fin(profiles_f);

    bool exist = false;

    while (fin >> temp) {
        if (t == temp) {
            if (temp.get_role() == Role::admin){

                hide();
                adminPanel = new Admin();
                adminPanel->show();
                exist = true;
                break;
            }
            else if (temp.get_role() == Role::user)
            {

                hide();
                studentPanel = new Student();
                studentPanel->show();
                exist = true;
                break;
            }
        }
    }
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
    fin.close();

}


void Auth::on_pushButton_4_clicked()
{

    std::ofstream fout(undefined_f, std::ios::app);

    QString un = ui->lineEdit_username->text();
    QString pw = ui->lineEdit_password->text();

    User t(un.toStdString(),pw.toStdString(),Role::undefined);
    fout << t;
    fout.close();
}

