#ifndef VIEW_EXAM_H
#define VIEW_EXAM_H

#include <QDialog>


#include <QGroupBox>
#include "exam_db_manager.h"

#include "Task.h"

class QRadioButton;

namespace Ui {
class view_exam;
}

class view_exam : public QDialog
{
    Q_OBJECT

public:
    explicit view_exam(QWidget *parent = nullptr);
    ~view_exam();

    void set_db (exam_db_manager &db_c){
        db = db_c;
                qDebug()<<"Set DB";
    }
    void set_ui();


private slots:
    void on_pushButton_3_clicked();

private:
    Ui::view_exam *ui;

signals:
    void hide_this();
private:
    int questions;
    std::vector<Task> tasks;
    exam_db_manager db;
    QGroupBox *createFirstExclusiveGroup(int number_of_question,int number_of_options,std::vector<std::string> options, std::string question);
};

#endif // VIEW_EXAM_H
