#include "exam_db_manager.h"

#include "Task.h"

exam_db_manager::exam_db_manager()
{

}

void exam_db_manager::set_Db(const QString path)
{
    examdb = QSqlDatabase::addDatabase("QSQLITE");
    examdb.setDatabaseName(path);

    if(!examdb.open()){
        qDebug()<<"Something has gone wrong!";
    }

    QString s_query = "CREATE TABLE exam ("
                    "Options_number integer,"
                    "Correct_answer integer,"
                    "Question TEXT,"
                    "Option_1 TEXT,"
                    "Option_2 TEXT,"
                    "Option_3 TEXT,"
                    "Option_4 TEXT,"
                    "Option_5 TEXT,"
                    "Option_6 TEXT,"
                    "Tasks_number integer,"
                    "Test_info TEXT"
                       ");";

    QSqlQuery query(examdb);

    query.exec(s_query);
}

bool exam_db_manager::add_record(int number_of_options, int correct_answer, QString question, std::vector<QString> options)
{
    bool success = false;
    QString qQuestion = question;

    QString S= "INSERT INTO exam (Options_number,Correct_answer,Question";
    for(int i = 1;i <= number_of_options;i++){
        S += ",Option_";
        S += QString::number(i);
    }

    S += ") VALUES (:options_number,:correct_answer,:question";

    for(int i = 1;i <= number_of_options;i++){
        S += ",:option_";
        S += QString::number(i);
    }
    S+=")";
    qDebug()<<S;

    QSqlQuery query(examdb);
    query.prepare(S);

    query.bindValue(":options_number",number_of_options);
    query.bindValue(":correct_answer",correct_answer);
    query.bindValue(":question",qQuestion);

    for(int i = 1;i <= number_of_options;i++){
        query.bindValue(":option_"+QString::number(i),options[i-1]);
    }





    if(query.exec()){
        success = true;
    }else
    {
        qDebug()<<"Query error: " <<query.lastError();
    }
    return success;
}

bool exam_db_manager::add_record(int number_of_tasks, QString test_info)
{
    bool success = false;

    QSqlQuery query(examdb);
    query.prepare("INSERT INTO exam (Tasks_number,Test_info) VALUES (:number,:info)");
    query.bindValue(":number",number_of_tasks);
    query.bindValue(":info",test_info);
    if(query.exec()){
        success = true;
    }else
    {
        qDebug()<<"Query error: " <<query.lastError();
    }
    return success;
}

bool exam_db_manager::update_info(QString test_info)
{
    bool success = false;

    QSqlQuery query(examdb);
    query.prepare("UPDATE exam SET Test_info=:info WHERE test_info IS NOT NULL");
    query.bindValue(":info",test_info);
    if(query.exec()){
        success = true;
    }else
    {
        qDebug()<<"Query error: " <<query.lastError();
    }
    return success;
}

bool exam_db_manager::update_info(int number_of_tasks)
{
    bool success = false;

    QSqlQuery query(examdb);
    query.prepare("UPDATE exam SET Tasks_number=:number WHERE test_info IS NOT NULL");
    query.bindValue(":number",number_of_tasks);
    if(query.exec()){
        success = true;
    }else
    {
        qDebug()<<"Query error: " <<query.lastError();
    }
    return success;
}

bool exam_db_manager::delete_question(QString question)
{
    bool success = false;

    QSqlQuery query(examdb);
    query.prepare("DELETE FROM exam WHERE Question=:info");
    query.bindValue(":info",question);
    if(query.exec()){
        success = true;
    }else
    {
        qDebug()<<"Query error: " <<query.lastError();
    }
    return success;
}

QString exam_db_manager::get_test_info()
{
    QSqlQuery query(examdb);
    query.prepare("SELECT * FROM exam WHERE test_info IS NOT NULL");
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    query.first();
    int column = query.record().indexOf("Test_info");
    QString info = "";

    info =query.value(column).toString();

    return info;
}

int exam_db_manager::get_tasks_count()
{
    QSqlQuery query(examdb);
    query.prepare("SELECT * FROM exam WHERE test_info IS NOT NULL");
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    query.first();
    int column = query.record().indexOf("Tasks_number");
    int info = 0;

    info =query.value(column).toInt();

    return info;
}

std::vector<Task> exam_db_manager::get_tasks()
{
    QSqlQuery query(examdb);
    query.prepare("SELECT * FROM exam WHERE Options_number IS NOT NULL");
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    // query.first();

    int options_number;
    int Correct_answer;
    std::string Question;
    std::vector<std::string> options;
    std::vector<Task> tasks;

    while(query.next()){
        options.clear();
        options_number =query.value(query.record().indexOf("Options_number")).toInt();
        Correct_answer =query.value(query.record().indexOf("Correct_answer")).toInt();
        Question =query.value(query.record().indexOf("Question")).toString().toStdString();
        for(int i = 1;i <= options_number; i++ ){
            options.push_back(query.value(query.record().indexOf("Option_"+QString::number(i))).toString().toStdString());
        }
        qDebug() << "NEW LOOP CYCLE";
        for(auto i: options){
            qDebug() << i;
        }
        tasks.push_back(Task(options_number,Correct_answer,Question,options));
    }


    return tasks;
}

