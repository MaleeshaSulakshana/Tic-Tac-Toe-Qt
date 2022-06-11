#include "gamemenuwindow.h"
#include "ui_gamemenuwindow.h"

#include "mainwindow.h"

GameMenuWindow::GameMenuWindow(QWidget *parent, const QString & gameText) :
    QMainWindow(parent),
    ui(new Ui::GameMenuWindow)
{
    ui->setupUi(this);

    ui->labelText->setText(gameText);
}

GameMenuWindow::~GameMenuWindow()
{
    delete ui;
}

void GameMenuWindow::on_pushButtonAgain_clicked()
{
//    Open game menu window
    MainWindow *parentWindow =
            dynamic_cast<MainWindow *>( this->parent() );
    this->hide();
    parentWindow->show();
}

void GameMenuWindow::on_pushButtonExit_clicked()
{
    QCoreApplication::quit();
}
