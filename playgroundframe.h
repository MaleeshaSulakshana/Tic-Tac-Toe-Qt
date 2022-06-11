#ifndef PLAYGROUNDFRAME_H
#define PLAYGROUNDFRAME_H

#include <QFrame>

namespace Ui {
class playGroundFrame;
}

class playGroundFrame : public QFrame
{
    Q_OBJECT

public:
    static const uint NUMBER_FIELDS = 9;

    explicit playGroundFrame(QWidget *parent = 0);
    ~playGroundFrame();

private:
    Ui::playGroundFrame *ui;
};

#endif // PLAYGROUNDFRAME_H
