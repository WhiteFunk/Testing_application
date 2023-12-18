#include "unregistered.h"
#include "ui_unregistered.h"

#include <fstream>


#define  profiles_f std::string("profiles.txt")
#define  buff_f std::string("buffer.txt")
#define  cars_f std::string("cars.txt")
#define  undefined_f std::string("undefined.txt")


Unregistered::Unregistered(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Unregistered)
{
    ui->setupUi(this);

    std::ifstream fin(undefined_f);

    User temp;
    while(fin >> temp){
        t.push_back(temp);
    }
    this->current = 0;
    set_text();
    fin.close();
}

Unregistered::~Unregistered()
{
    delete ui;
}

void Unregistered::set_text()
{
    if(current != t.size())
    ui->textBrowser->setText(QString::fromStdString(t[current].get_username())+ "\n"+QString::number(t[current].get_saltedPassword()));
    else
    on_close();

}

void Unregistered::on_pushButton_2_clicked()
{
    std::ofstream fout(profiles_f, std::ios::app);
    qDebug() << ui->comboBox->currentIndex();
    t[current].set_role(static_cast<Role>(ui->comboBox->currentIndex()));
    fout << t[current];
    current++;
    set_text();
    fout.close();
}


void Unregistered::on_pushButton_clicked()
{
    current++;
    set_text();
}

