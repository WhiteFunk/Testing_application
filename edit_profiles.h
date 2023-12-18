#ifndef EDIT_PROFILES_H
#define EDIT_PROFILES_H

#include <QDialog>
#include <QTextBrowser>

namespace Ui {
class edit_profiles;
}

class edit_profiles : public QDialog
{
    Q_OBJECT

public:
    explicit edit_profiles(QWidget *parent = nullptr);
    ~edit_profiles();

signals:
    void hide_this();

private slots:
    void on_pushButton_4_clicked();

    void on_add_new_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::edit_profiles *ui;
    QTextBrowser *profiles;
};

#endif // EDIT_PROFILES_H
