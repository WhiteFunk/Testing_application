#ifndef EXAM_H
#define EXAM_H

#include <QDialog>

#include <QGroupBox>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include "exam_db_manager.h"

#include "Task.h"

class QRadioButton;

namespace Ui {
class Exam;
}

class Exam : public QDialog
{
    Q_OBJECT

public:


    explicit Exam(QWidget *parent = nullptr);
    ~Exam();

    void set_db (exam_db_manager &db_c){
        db = db_c;
    }
    void set_ui();

    void set_timer(QTime t){
        time = t;
        qDebug() << time;
    }

    public slots:
    void updateDateTime();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

signals:
    void hide_this();
private:
    Ui::Exam *ui;
    QTime time;
    QTimer *timer;

    int questions;
    std::vector<Task> tasks;
    std::vector<std::vector<QRadioButton*>> buttons;
    exam_db_manager db;
    QGroupBox *createFirstExclusiveGroup(int number_of_question,int number_of_options,std::vector<std::string> options, std::string question);



};

#endif // EXAM_H
