#ifndef INGAME_H
#define INGAME_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class InGame;
}

class InGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit InGame(QMainWindow *parent = nullptr);
    ~InGame();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::InGame *ui;
    void saveRecord(QString name, int ur, int bot);
};

#endif // INGAME_H
