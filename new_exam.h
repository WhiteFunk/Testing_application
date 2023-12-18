#ifndef NEW_EXAM_H
#define NEW_EXAM_H

#include <QDialog>
#include "exam_db_manager.h"
#include "new_question.h"

namespace Ui {
class new_exam;
}

class new_exam : public QDialog
{
    Q_OBJECT

public:
    explicit new_exam(QWidget *parent = nullptr);
    ~new_exam();

signals:
    void on_close();

private slots:
    void on_pushButton_clicked();
    void show_this(){
        show();
        delete question_panel;
    }

private:
    Ui::new_exam *ui;

    new_question *question_panel;
    exam_db_manager db;
};

#endif // NEW_EXAM_H
