#include "spaceinvaders.h"
#include<QTimer>


CSpaceInvaders::CSpaceInvaders(QSize oScreenSize, QWidget *pParent)
   : QGraphicsView(pParent),m_oScreenSize(oScreenSize)
{
    QGraphicsScene*pScene=new QGraphicsScene();
    setScene(pScene);
    pScene->setSceneRect(0,0,m_oScreenSize.width(),m_oScreenSize.height());
    setBackgroundBrush(QBrush(QImage(":/images/SpaceInvadersBg.jpg")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::PointingHandCursor);
    setStyleSheet(("border-style:none"));
}

void CSpaceInvaders::Run()
{
    scene()->clear();
    setCursor(Qt::BlankCursor);
    m_p_Canon=new CCanon(EColor::Red);
    m_p_Canon->setPos(m_oScreenSize.width()/2,m_oScreenSize.height()-gCannonSize.height());
    m_p_Canon->setFlag(QGraphicsItem::ItemIsFocusable);
    m_p_Canon->setFocus();
    scene()->addItem(m_p_Canon);

    connect(m_p_Canon,&CCanon::sigIncreaseScore,this,&CSpaceInvaders::onIncreaseScore);
    connect(m_p_Canon,&CCanon::sigDecreaseScore,this,&CSpaceInvaders::onDecreaseScore);

    m_pPoints=new CPoints();
    scene()->addItem(m_pPoints);

    QTimer*pTimer=new QTimer(this);
    connect(pTimer,&QTimer::timeout,this,&CSpaceInvaders::onCreateEnemy);
    pTimer->start(2000);


}
void CSpaceInvaders::CheckPoints()
{
    if((m_pPoints->GetScore()<0)||(m_pPoints->GetHealth()<=0)){
        m_pPoints->Reset();
        onGameOver();
    }
}


void CSpaceInvaders::keyPressEvent(QKeyEvent *pEvent)
{
    if(m_p_Canon==nullptr){
        return;
    }
    switch(pEvent->key()){
        case Qt::Key_Left:
        if(m_p_Canon->pos().x()>0)
            m_p_Canon->setPos(m_p_Canon->x()-20,m_p_Canon->y());
        break;
    case Qt::Key_Right:
        if((m_p_Canon->pos().x()+gCannonSize.width())<m_oScreenSize.width())
            m_p_Canon->setPos(m_p_Canon->x()+20,m_p_Canon->y());
        break;

    case Qt::Key_Z:
    {
        int nColor=static_cast<int>(m_p_Canon->GetColor());
        m_p_Canon->SetColor(static_cast<EColor>(++nColor));
        break;
    }
    case Qt::Key_Space:
        m_p_Canon->Shoot();
        break;
    }
}

void CSpaceInvaders::onCreateEnemy()
{
    int nPos=100+(rand()%m_oScreenSize.width()-100);
    int nColor=rand()%3;

    CAlien*pAlien=new CAlien(static_cast<EColor>(nColor));
    pAlien->setPos(nPos,0);
    scene()->addItem(pAlien);
    connect(pAlien,&CAlien::sigGameOver,this,&CSpaceInvaders::onGameOver);
    connect(pAlien,&CAlien::sigDecreaseHEalth,this,&CSpaceInvaders::onDecreaseHealth);

}

void CSpaceInvaders::onIncreaseScore()
{
    m_pPoints->IncreaseScore();
    CheckPoints();

}

void CSpaceInvaders::onDecreaseScore()
{
    m_pPoints->DecreaseScore();
    CheckPoints();
}

void CSpaceInvaders::onDecreaseHealth()
{
    m_pPoints->DecreaseHealth();
    CheckPoints();
}

void CSpaceInvaders::onGameOver()
{
    close();
}
