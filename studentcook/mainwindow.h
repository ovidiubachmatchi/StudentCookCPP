#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include <QtSql>
#include <QSqlDatabase>
#include <QImageReader>
#include <QEventLoop>
#include <QRegularExpression>
#include <QNetworkAccessManager>
#include <QNetworkReply>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:    
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    void exit_db();
    void add_ingredient();
    void delete_ingredient();
    void clear();
    void downloadFinished(QNetworkReply *);
    void show_recipes();
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
