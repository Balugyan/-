#ifndef RECORDSTABLE_H
#define RECORDSTABLE_H

#include <QException>
#include <QMainWindow>
#include <QWidget>

class NoDataFileException : public QException{
public:
    NoDataFileException() {

    }
};




namespace Ui {
class RecordsTable;
}

class RecordsTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit RecordsTable(QMainWindow *parent = nullptr);
    ~RecordsTable();

private:
    Ui::RecordsTable *ui;
};

#endif // RECORDSTABLE_H
