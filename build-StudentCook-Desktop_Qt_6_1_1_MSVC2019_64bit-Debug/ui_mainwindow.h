/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *add_ingredient;
    QLineEdit *input;
    QLabel *ingredients;
    QPushButton *delete_ingredient;
    QPushButton *clear;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *recipes;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *show_recipes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1030, 600);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(21, 5, 19, 255), stop:1 rgba(46, 19, 74, 255))"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        add_ingredient = new QPushButton(centralwidget);
        add_ingredient->setObjectName(QString::fromUtf8("add_ingredient"));
        add_ingredient->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 11pt;\n"
"\n"
"border: 2px solid white;\n"
"border-radius: 3px;"));

        gridLayout_2->addWidget(add_ingredient, 1, 0, 1, 1);

        input = new QLineEdit(centralwidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"background-color:  rgb(0, 0, 0);\n"
"QListView::item {\n"
"    	margin: 2px;\n"
"    }\n"
"     \n"
"    QListView::item:selected {\n"
"    	background: orange;\n"
"    }\n"
""));
        input->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        input->setCursorMoveStyle(Qt::LogicalMoveStyle);
        input->setClearButtonEnabled(true);

        gridLayout_2->addWidget(input, 0, 0, 1, 2);

        ingredients = new QLabel(centralwidget);
        ingredients->setObjectName(QString::fromUtf8("ingredients"));
        ingredients->setMinimumSize(QSize(355, 0));
        ingredients->setMaximumSize(QSize(355, 16777215));
        ingredients->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"font:  20pt;\n"
"color: white;"));
        ingredients->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(ingredients, 2, 0, 5, 2);

        delete_ingredient = new QPushButton(centralwidget);
        delete_ingredient->setObjectName(QString::fromUtf8("delete_ingredient"));
        delete_ingredient->setStyleSheet(QString::fromUtf8("font: 11pt;\n"
"color: white;\n"
"border: 2px solid white;\n"
"border-radius: 3px;"));

        gridLayout_2->addWidget(delete_ingredient, 1, 1, 1, 1);

        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setLayoutDirection(Qt::LeftToRight);
        clear->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 12pt;\n"
"\n"
"border: 2px solid white;\n"
"border-radius: 3px;"));

        gridLayout_2->addWidget(clear, 7, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 4, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        recipes = new QScrollArea(centralwidget);
        recipes->setObjectName(QString::fromUtf8("recipes"));
        recipes->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 15pt;\n"
"border: 1px solid white;\n"
"border-radius: 3px;"));
        recipes->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 636, 519));
        recipes->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(recipes);


        verticalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout, 3, 0, 1, 1);

        show_recipes = new QPushButton(centralwidget);
        show_recipes->setObjectName(QString::fromUtf8("show_recipes"));
        show_recipes->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 20pt;\n"
"\n"
"border: 2px solid white;\n"
"border-radius: 3px;"));

        gridLayout->addWidget(show_recipes, 0, 0, 3, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        add_ingredient->setText(QCoreApplication::translate("MainWindow", "Add\n"
" ingredient", nullptr));
        input->setText(QString());
        ingredients->setText(QCoreApplication::translate("MainWindow", "There are no ingredients", nullptr));
        delete_ingredient->setText(QCoreApplication::translate("MainWindow", "Delete\n"
" ingredient", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear ingredients", nullptr));
        show_recipes->setText(QCoreApplication::translate("MainWindow", "Show recipes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
