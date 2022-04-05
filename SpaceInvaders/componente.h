#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <QGraphicsPixmapItem>
#include<QGraphicsSimpleTextItem>
#include<QGraphicsItem>
#include<QKeyEvent>
#include"setari.h"
enum class EColor{
    Red,Pink,Blue
};
class CBullet;
class CCanon:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   CCanon(EColor eColor,QGraphicsItem*pParent=nullptr);
   void Shoot();
   EColor GetColor() const;
   void SetColor(EColor eColor);
signals:
   void sigIncreaseScore();
   void sigDecreaseScore();
private:
   EColor m_eColor;
};

///////////////////////////////////////////////////////////////////////////////////
class CAlien:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CAlien(EColor eColor,QGraphicsItem*pParent=nullptr);
    EColor GetColor() const;
    void SetColor(EColor eColor);

signals:
    void sigDecreaseHEalth();
    void sigGameOver();
public slots:
    void onMove();
private:
    EColor m_eColor;


};

////////////////////
///
class CBullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CBullet(EColor eColor,QGraphicsItem*pParent=nullptr);
    EColor GetColor() const;
    void SetColor(EColor eColor);

signals:
    void sigIncreaseScore();
    void sigDecreaseScore();
public:
    void onMove();
private:
    EColor m_eColor;

};

////////////////
class CPoints: public QGraphicsTextItem
{
public:
    CPoints(QGraphicsItem*pParent=nullptr);
    void IncreaseScore();
    void DecreaseScore();
    void DecreaseHealth();
    int GetHealth() const;
    int GetScore() const;
    void Reset();
private:
    int m_nHealth=gMaxHealth;
    int m_nScore=0;

};


#endif // COMPONENTE_H
