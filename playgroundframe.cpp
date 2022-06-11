#include "playgroundframe.h"
#include "ui_playgroundframe.h"

#include "mainwindow.h"

#include <QDebug>

playGroundFrame::playGroundFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::playGroundFrame)
{
    ui->setupUi(this);

    MainWindow *parentWindow =
            dynamic_cast<MainWindow *>( this->parent() );

    QString btn1 = "padding: 0px; margin: 0px; border: 0px solid black; color: #F6F6F6;"
            "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #3E065F, stop: 0.4 #700B97, stop:1 #8E05C2);"
            "font-size: 40pt; border-radius: 20px";

    this->ui->pushButton_1_1->setStyleSheet(btn1);

    this->ui->pushButton_1_1->setText( "" );
    QObject::connect( this->ui->pushButton_1_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,1 );
    });
    parentWindow->addButton( this->ui->pushButton_1_1, 1, 1 );

    this->ui->pushButton_1_2->setText( "" );
    QObject::connect( this->ui->pushButton_1_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,2 );
    });
    parentWindow->addButton( this->ui->pushButton_1_2, 1, 2 );

    this->ui->pushButton_1_3->setText( "" );
    QObject::connect( this->ui->pushButton_1_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,3 );
    });
    parentWindow->addButton( this->ui->pushButton_1_3, 1, 3 );

    this->ui->pushButton_2_1->setText( "" );
    QObject::connect( this->ui->pushButton_2_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,1 );
    });
    parentWindow->addButton( this->ui->pushButton_2_1, 2, 1 );

    this->ui->pushButton_2_2->setText( "" );
    QObject::connect( this->ui->pushButton_2_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,2 );
    });
    parentWindow->addButton( this->ui->pushButton_2_2, 2, 2 );

    this->ui->pushButton_2_3->setText( "" );
    QObject::connect( this->ui->pushButton_2_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,3 );
    });
    parentWindow->addButton( this->ui->pushButton_2_3, 2, 3 );

    this->ui->pushButton_3_1->setText( "" );
    QObject::connect( this->ui->pushButton_3_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,1 );
    });
    parentWindow->addButton( this->ui->pushButton_3_1, 3, 1 );

    this->ui->pushButton_3_2->setText( "" );
    QObject::connect( this->ui->pushButton_3_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,2 );
    });
    parentWindow->addButton( this->ui->pushButton_3_2, 3, 2 );

    this->ui->pushButton_3_3->setText( "" );
    QObject::connect( this->ui->pushButton_3_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,3 );
    });
    parentWindow->addButton( this->ui->pushButton_3_3, 3, 3 );
}

playGroundFrame::~playGroundFrame()
{
    delete ui;
}
