#include "componente.h"
#include<QTimer>
#include<QGraphicsScene>
CCanon::CCanon(EColor eColor, QGraphicsItem *pParent):QGraphicsPixmapItem(pParent)
{
    SetColor(eColor);
}

void CCanon::Shoot()
{
    CBullet*pBullet=new CBullet(m_eColor);
    connect(pBullet,&CBullet::sigIncreaseScore,this,&CCanon::sigIncreaseScore);
    connect(pBullet,&CBullet::sigDecreaseScore,this,&CCanon::sigDecreaseScore);

    pBullet->setPos(x()+27,y()-10);
    scene()->addItem(pBullet);


}

EColor CCanon::GetColor() const
{
   return m_eColor;
}

void CCanon::SetColor(EColor eColor)
{
   m_eColor=eColor;
   switch(eColor){
      case EColor::Red:
      {
        QPixmap oPixmap(":/images/RedCannon.png");
        setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
        break;
      }
      case EColor::Pink:
      {
       QPixmap oPixmap(":/images/PinkCannon.png");
       setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
       break;

      }
      case EColor::Blue:
      {
       QPixmap oPixmap(":/images/BlueCannon.png");
       setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
       break;
      }
      default:
      {
       QPixmap oPixmap(":/images/RedCannon.png");
       setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
       m_eColor=EColor::Red;

      }
   }
}

CAlien::CAlien(EColor eColor, QGraphicsItem *pParent):QGraphicsPixmapItem(pParent)
{
    SetColor(eColor);
    QTimer*pTimer=new QTimer(this);
    connect(pTimer,&QTimer::timeout,this,&CAlien::onMove);
    pTimer->start(gAlienSpeed);
}

EColor CAlien::GetColor() const
{
    return m_eColor;
}

void CAlien::SetColor(EColor eColor)
{
    m_eColor=eColor;

    switch(eColor){
       case EColor::Red:
       {
         QPixmap oPixmap(":/images/RedAlien.png");
         setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
         break;
       }
       case EColor::Pink:
       {
        QPixmap oPixmap(":/images/PinkAlien.png");
        setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
        break;

       }
       case EColor::Blue:
       {
        QPixmap oPixmap(":/images/BlueAlien.png");
        setPixmap(oPixmap.scaled(QSize(100,100),Qt::KeepAspectRatio));
        break;
       }

    }
}

void CAlien::onMove()
{
    setPos(x(),y()+5);
    if((pos().y())>=(scene()->height()-gCannonSize.height()))
    {
        scene()->removeItem(this);
        emit sigDecreaseHEalth();
        delete this;
    }

    QList<QGraphicsItem*> lstCollidingItem= collidingItems();
    for(auto const pItem:lstCollidingItem)
    {
        if(dynamic_cast<CCanon*>(pItem))
          // emit sigIncreaseScore();
            emit sigGameOver();

    }
}

////////////////////////////////////////////

CBullet::CBullet(EColor eColor, QGraphicsItem *pParent):QGraphicsPixmapItem(pParent)
{
    SetColor(eColor);
    QTimer*pTimer=new QTimer(this);
    connect(pTimer,&QTimer::timeout,this,&CBullet::onMove);
    pTimer->start(gBulletSpeed);

}

EColor CBullet::GetColor() const
{
    return m_eColor;
}

void CBullet::SetColor(EColor eColor)
{
    m_eColor=eColor;
    switch(eColor){
       case EColor::Red:
       {
         QPixmap oPixmap(":/images/RedBullet.png");
         setPixmap(oPixmap.scaled(QSize(40,40),Qt::KeepAspectRatio));
         break;
       }
       case EColor::Pink:
       {
        QPixmap oPixmap(":/images/PinkBullet.png");
        setPixmap(oPixmap.scaled(QSize(40,40),Qt::KeepAspectRatio));
        break;

       }
       case EColor::Blue:
       {
        QPixmap oPixmap(":/images/BlueBullet.png");
        setPixmap(oPixmap.scaled(QSize(40,40),Qt::KeepAspectRatio));
        break;
       }

    }

}

void CBullet::onMove()
{
    QList<QGraphicsItem*>lstCollidingItem=collidingItems();
    for(auto const pItem:lstCollidingItem){
        CAlien*pAlien=dynamic_cast<CAlien*>(pItem);
        if(pAlien!=nullptr)
        {
            if(pAlien->GetColor()==GetColor())
            {
                scene()->removeItem(pAlien);
                scene()->removeItem(this);
                emit sigIncreaseScore();
                delete pAlien;
                delete this;
            }
            else
            {
                emit sigDecreaseScore();
                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}


////////////////////////

CPoints::CPoints(QGraphicsItem *pParent):QGraphicsTextItem(pParent)
{
    setPlainText(QString("Health: ")+QString::number(m_nHealth)+"\n"+QString("Score: ")+QString::number(m_nScore));
    setDefaultTextColor((Qt::red));
    setFont(QFont("times",24));


}

void CPoints::IncreaseScore()
{
    m_nScore+=50;
    setPlainText(QString("Health: ")+QString::number(m_nHealth)+"\n"+QString("Score: ")+QString::number(m_nScore));
}

void CPoints::DecreaseScore()
{
    m_nScore-=50;
    setPlainText(QString("Health: ")+QString::number(m_nHealth)+"\n"+QString("Score: ")+QString::number(m_nScore));
}

void CPoints::DecreaseHealth()
{
    m_nHealth--;
    setPlainText(QString("Health: ")+QString::number(m_nHealth)+"\n"+QString("Score: ")+QString::number(m_nScore));
}

int CPoints::GetHealth() const
{
    return m_nHealth;
}

int CPoints::GetScore() const
{
    return m_nScore;
}

void CPoints::Reset()
{
    m_nScore=0;

    m_nHealth=gMaxHealth;
    setPlainText(QString("Health: ")+QString::number(m_nHealth)+"\n"+QString("Score: ")+QString::number(m_nScore));

}