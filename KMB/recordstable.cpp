#include "recordstable.h"
#include "ui_recordstable.h"

#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QTableWidget>

RecordsTable::RecordsTable(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::RecordsTable)
{
    ui->setupUi(this);
    // Если файла с рекордами не существует, то вызывается исключение
    QString filename = "Data.txt";
    if(!QFile::exists(filename))
        throw new NoDataFileException();


    // Создание объекта таблицы рекордов
    QTableWidget *w = new QTableWidget(this);
    w->setColumnCount(3);
    w->setHorizontalHeaderItem(0, new QTableWidgetItem("Имя игрока"));
    w->setHorizontalHeaderItem(1, new QTableWidgetItem("Выбор игрока"));
    w->setHorizontalHeaderItem(2, new QTableWidgetItem("Выбор бота"));


    // Заполнение таблицы
    QFile file (filename);
    QTextStream stream(&file);
    int i = 0;
    if (file.open(QIODevice::ReadOnly)) {
        while(!stream.atEnd()){
            QString name;
            int ur;
            int bot;
            stream >> name >> ur >> bot;
            if(name.length() > 0){
                w->setRowCount(w->rowCount() + 1);
                w->setItem(i, 0, new QTableWidgetItem(name));
                w->setItem(i, 1, new QTableWidgetItem(ur==0?"Камень":(ur == 1 ? "Ножницы" : "Бумага")));
                w->setItem(i++, 2, new QTableWidgetItem(bot==0?"Камень":(bot == 1 ? "Ножницы" : "Бумага")));
            }
        }
    }
    w->resize(this->width() - 10, this->height() - 10);
    w->move(5, 5);
}

RecordsTable::~RecordsTable()
{
    delete ui;
}

