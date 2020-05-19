#include <QTimer>
#include <QCloseEvent>
#include <QDesktopWidget>

#include "TwFiveScreen.h"
#include "ui_TwFiveScreen.h"

// TODO: add drawing on screen instead window
// TODO: add drawing slideshow of photos of chosen folder during 25 mode
// TODO: add flowing words moving on the screen or window
// TODO: add all these 3 25 modes to setting dialog

TwFiveScreen::TwFiveScreen()
{
}

TwFiveScreen::TwFiveScreen(QWidget * parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    m_pWindow = new Ui::TwFiveForm();
    m_pWindow->setupUi(this);
    
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //m_pWindow->graphicsView->setAttribute(Qt::WA_TranslucentBackground);

    m_pScene = new QGraphicsScene(m_pWindow->graphicsView);
    m_pOriginItem = m_pScene->addText("1");
    m_pTranslatedItem = m_pScene->addText("2");
    // m_pScene->setBackgroundBrush(Qt::transparent);
    m_pScene->setSceneRect(QApplication::desktop()->screenGeometry());

    m_itemsFont.setPointSize(22);
    m_itemsFont.setBold(true);

    m_pOriginItem->setFont(m_itemsFont);
    m_pTranslatedItem->setFont(m_itemsFont);

    m_pWindow->graphicsView->setScene(m_pScene);
//    m_pWindow->graphicsView->hide();

    m_p25_Timer = new QTimer();
    connect(m_p25_Timer, SIGNAL(timeout()), this, SLOT(on25_TimerEvent()));
}

TwFiveScreen::~TwFiveScreen()
{
    delete m_p25_Timer;
}

// protected functions

void TwFiveScreen::showEvent(QShowEvent *event)
{
    m_p25_Timer->start(M_SEC_25_MODE);
    QWidget::showEvent(event);
}

void TwFiveScreen::closeEvent(QCloseEvent *event)
{
    m_p25_Timer->stop();
    QWidget::closeEvent(event);
}

// protected slots

void TwFiveScreen::on25_TimerEvent()
{
    setWordGroup(Document::getInstance()->getRandomWordGroup());
}

// public functions

void TwFiveScreen::setWordGroup(WordGroup wordGroup)
{
    m_pOriginItem->setPlainText(wordGroup.first);
    m_pTranslatedItem->setPlainText(wordGroup.second);
    float space = 20;
    float widthBothWords = m_pOriginItem->boundingRect().width() + m_pTranslatedItem->boundingRect().width() + space;
    float x = (QApplication::desktop()->screenGeometry().width() - widthBothWords) / 2;
    float y = QApplication::desktop()->screenGeometry().height() / 2 - m_pOriginItem->boundingRect().height();
    m_pOriginItem->setPos(x, y);
    m_pTranslatedItem->setPos(x + m_pOriginItem->boundingRect().width() + space, y);
}
