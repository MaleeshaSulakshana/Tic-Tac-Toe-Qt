#ifndef GAMEMENUWINDOW_H
#define GAMEMENUWINDOW_H

#include <QMainWindow>

//#include "mainwindow.h"

namespace Ui {
class GameMenuWindow;
}

class GameMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMenuWindow(QWidget *parent, const QString & gameText);
    ~GameMenuWindow();

private slots:
    void on_pushButtonAgain_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::GameMenuWindow *ui;
//    MainWindow *mainWindow;

};

#endif // GAMEMENUWINDOW_H
