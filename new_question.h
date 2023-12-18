#ifndef NEW_QUESTION_H
#define NEW_QUESTION_H

#include <QDialog>
#include "exam_db_manager.h"

namespace Ui {
class new_question;
}

class new_question : public QDialog
{
    Q_OBJECT

public:
    explicit new_question(QWidget *parent = nullptr);
    ~new_question();

    void set_db (exam_db_manager &db_c){
        db = db_c;
    }

    void set_questions (int questions){
        this->questions = questions;
    }

signals:
    void hide_this();
private slots:
    void on_pushButton_clicked();

private:
    Ui::new_question *ui;
    exam_db_manager db;
    int questions;
};

#endif // NEW_QUESTION_H
