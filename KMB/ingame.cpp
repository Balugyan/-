#include "ingame.h"
#include "ui_ingame.h"
#include <QTextStream>
#include <QFile>
#include <QDataStream>

// Конструктор для игрового окна
InGame::InGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::InGame)
{
    ui->setupUi(this);

    // Делаем все картинки невидимыми
    ui->player_k->setVisible(true);
    ui->player_n->setVisible(false);
    ui->player_b->setVisible(false);
    ui->bot_k->setVisible(false);
    ui->bot_n->setVisible(false);
    ui->bot_b->setVisible(false);
}

InGame::~InGame()
{
    delete ui;
}

void InGame::on_pushButton_clicked()
{
    // Тут реализуется игровая механика: создается случайное число и в зависимости от его значения определяется, что выбрал бот.
    if(ui->lineEdit->text().length() <= 0)
        ui->label->setText("Введите имя!");
    else{
        int res = rand() % 3;
        switch(res){
            case 0:
            ui->bot_k->setVisible(true);
            ui->bot_n->setVisible(false);
            ui->bot_b->setVisible(false);
            break;
            case 1:
            ui->bot_k->setVisible(false);
            ui->bot_n->setVisible(true);
            ui->bot_b->setVisible(false);
            break;
            case 2:
            ui->bot_k->setVisible(false);
            ui->bot_n->setVisible(false);
            ui->bot_b->setVisible(true);
            break;
        }

        if(ui->comboBox->currentIndex() == res)
            ui->label->setText("Ничья!");
        else
            switch(res){
            case 0:
                if(ui->comboBox->currentIndex() == 1){
                    ui->label->setText("Вы проиграли!");
                }
                if(ui->comboBox->currentIndex() == 2){
                    ui->label->setText("Вы победили!");
                    saveRecord(ui->lineEdit->text(), ui->comboBox->currentIndex(), res);
                }
                break;
            case 1:
                if(ui->comboBox->currentIndex() == 2){
                    ui->label->setText("Вы проиграли!");
                }
                if(ui->comboBox->currentIndex() == 0){
                    ui->label->setText("Вы победили!");
                    saveRecord(ui->lineEdit->text(), ui->comboBox->currentIndex(), res);
                }
                break;
            case 2:
                if(ui->comboBox->currentIndex() == 0){
                    ui->label->setText("Вы проиграли!");
                }
                if(ui->comboBox->currentIndex() == 1){
                    ui->label->setText("Вы победили!");
                    saveRecord(ui->lineEdit->text(), ui->comboBox->currentIndex(), res);
                }
                break;
            }
    }
}

// Функция записи рекорда в файл
void InGame::saveRecord(QString name, int ur, int bot){
    QString filename = "Data.txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << name << " " << ur << " " << bot << "\n";
        }
}

// Меняет картинку, когда меняется выбранный жест
void InGame::on_comboBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        ui->player_k->setVisible(true);
        ui->player_n->setVisible(false);
        ui->player_b->setVisible(false);
        break;
    case 1:
        ui->player_k->setVisible(false);
        ui->player_n->setVisible(true);
        ui->player_b->setVisible(false);
        break;
    case 2:
        ui->player_k->setVisible(false);
        ui->player_n->setVisible(false);
        ui->player_b->setVisible(true);
        break;
    }
}

