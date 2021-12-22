#include "ingame.h"
#include "mainwindow.h"
#include "recordstable.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// При нажатии на кнопку "начать игру" создается новое окно игры
void MainWindow::on_pushButton_clicked()
{
    QMainWindow *w = new InGame(this);
    w->show();
}


// При нажатии на "Таблица рекордов" отрисовывается таблица рекордов (если файл существует, или же обрабатывает исключение)
void MainWindow::on_pushButton_2_clicked()
{
    try{
        QMainWindow *w = new RecordsTable(this);
        w->show();
    }
    catch(NoDataFileException *e){
        QMessageBox msgBox;
        msgBox.setText("Рекорды не найдены!");
        msgBox.exec();
    }
}

// Кнопка выхода
void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

// Удаляет файл с рекордами
void MainWindow::on_pushButton_4_clicked()
{
    QFile::remove("Data.txt");
    QMessageBox msgBox;
    msgBox.setText("Рекорды очищены!");
    msgBox.exec();
}

