#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        "QWidget {"
"background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(150, 150, 150, 255), stop:1 rgba(202, 202, 202, 255)); "
        "font: 14pt \"MS Shell Dlg 2\";"
        "font: bold;"
        "text-align:center;"
           " border-radius:7px;"
        "border:1px solid #aaa;"
        "color:#1a1a1a;}"

        "QLabel{"
        "border:0px solid #8c8c8c;"
        "background: transparent; "
        "}"

        "QLineEdit{"
        "border:1px solid #8c8c8c;"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(150, 150, 150, 255), stop:1 rgba(202, 202, 202, 255)); "
        "border-radius:7px;"
        "color:#1a1a1a;"
        "}"

        "QLineEdit:hover{"
        "border:1px solid #0078d7;"
        "}"

        "QPushButton"
        "{background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(150, 150, 150, 255), stop:1 rgba(202, 202, 202, 255)); "
           " border-radius:7px;"
        "border:1px solid #8c8c8c;"
        "color:#1a1a1a;"
            "icon-size: 16px;}"

       " QPushButton:hover"
       " {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #729fcf, stop:1 #d3d7cf);   "
               " border-radius:7px;"
           " border:1px solid #0078d7 inset;"
          "  color:#111;}"


        "QToolButton{"
            "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(150, 150, 150, 255), stop:1 rgba(202, 202, 202, 255));"
        "border-radius:15px;"
        "border:2px solid #8c8c8c;"
        "color:#1a1a1a;"
        "font-size: 8pt;"
        "icon-size: 16px;"
        "}"

        "QToolButton:hover{"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(200, 200, 200, 200), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:7px;"
        "border:1px solid #0078d7;"
        "color:#111;"
        "}");
    Auth w;
    w.show();
    return a.exec();
}
