#ifndef EXAM_DB_MANAGER_H
#define EXAM_DB_MANAGER_H

#include <QtSql>
#include <QFileInfo>
#include <QSqlQuery>

#include <vector>

class Task;

class exam_db_manager
{
public:
    exam_db_manager();

    void set_Db(const QString path);
    bool add_record(int number_of_options,int correct_answer,QString question, std::vector<QString> options);
    bool add_record(int number_of_tasks, QString test_info);

    bool update_info( QString test_info);
    bool update_info( int number_of_tasks);

    bool delete_question( QString question);

    QString get_test_info();
    int get_tasks_count();
    std::vector<Task> get_tasks();
private:
    QSqlDatabase examdb;
};

#endif // EXAM_DB_MANAGER_H
