#include "edit_profiles.h"
#include "ui_edit_profiles.h"

#include <QScrollArea>

#include "User.h"
#include <fstream>

#define  profiles_f std::string("profiles.txt")
#define  buff_f std::string("buffer.txt")
#define  cars_f std::string("cars.txt")
#define  undefined_f std::string("undefined.txt")

edit_profiles::edit_profiles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_profiles)
{
    ui->setupUi(this);

    QScrollArea *scrollArea = new QScrollArea();
    QVBoxLayout *groupBoxLayout = new QVBoxLayout();
    QWidget *widget = new QWidget();
    profiles = new QTextBrowser();
    ui->profiles->addWidget(scrollArea);
    scrollArea->setWidget(profiles);

    scrollArea->setFixedSize(600,200);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

edit_profiles::~edit_profiles()
{
    delete ui;
}

void edit_profiles::on_pushButton_4_clicked()
{
    hide_this();

}


void edit_profiles::on_add_new_clicked()
{
    std::ofstream fout(profiles_f, std::ios::app);

    QString un = ui->lineEdit_username->text();
    QString pw = ui->lineEdit_password->text();

    User t(un.toStdString(),pw.toStdString(),static_cast<Role>(ui->role->currentIndex()));

    fout << t;

    fout.close();
}

void WriteTobuf(std::string str)
{
    std::ifstream fin(str);
    std::ofstream fout(buff_f);
    User t;

    while (fin >> t) {
        fout << t;
    }

    fin.close();
    fout.close();
}



void edit_profiles::on_delete_2_clicked()
{

    QString un = ui->lineEdit_username->text();
    QString pw = ui->lineEdit_password->text();

    User t(un.toStdString(),pw.toStdString(),static_cast<Role>(ui->role->currentIndex()));

    WriteTobuf(std::string(profiles_f));

    std::ifstream fin(buff_f);
    std::ofstream fout(profiles_f);


    while (fin >> t) {
        if(!(t == t))
            fout << t;
    }

    fin.close();
    fout.close();
}


void edit_profiles::on_pushButton_clicked()
{
    std::ifstream fin(profiles_f);
    User t;

    QString temp;

    while (fin >> t) {
        temp += QString::fromStdString(t.get_username())+ "\n";
        temp += QString::number(t.get_saltedPassword())+ "\n";
        if(static_cast<int>(t.get_role()) == 0)
            temp += "Admin\n\n";
        else if (static_cast<int>(t.get_role()) == 1)
                temp +="User\n\n";
    }

    profiles->setText(temp);

    fin.close();
}

