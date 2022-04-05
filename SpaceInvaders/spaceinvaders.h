#ifndef CSPACEINVADERS_H
#define CSPACEINVADERS_H
#include<QPointer>
#include<QGraphicsView>
#include<QKeyEvent>
#include"componente.h"

class CSpaceInvaders:public QGraphicsView
{
    Q_OBJECT
public:
    CSpaceInvaders(QSize oScreenSize,QWidget*pParent=nullptr);
    void Run();
    void CheckPoints();
protected:
    void keyPressEvent(QKeyEvent*pEvent) override;
public slots:
    void onCreateEnemy();
    void onIncreaseScore();
    void onDecreaseScore();
    void onDecreaseHealth();
    void onGameOver();
private:
    CCanon*m_p_Canon=nullptr;
    CPoints* m_pPoints=nullptr;
    QSize m_oScreenSize;
};

#endif // CSPACEINVADERS_H
