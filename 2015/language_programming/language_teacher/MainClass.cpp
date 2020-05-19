#include "MainClass.h"
#include "PopupWindow.h"
#include "SettingsDialog.h"
#include "AddNewWordsDialog.h"
#include "XmlManager.h"
#include "TwFiveScreen.h"

#include <QtGui>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QStandardItemModel>
#include <QMessageBox>


MainClass::MainClass()
{
    m_pPopupTimer = new QTimer(this);
    m_pPopupMsgTimer = new QTimer(this);
    m_pPopupTimer->start(Document::getInstance()->getPopupInterval() * TIME_FORMAT);
    m_pPopupMsgTimer->start(Document::getInstance()->getMessagePopupInterval() * TIME_FORMAT);

    connect(m_pPopupTimer, SIGNAL(timeout()), this, SLOT(onPopupTimerEvent()));
    connect(m_pPopupMsgTimer, SIGNAL(timeout()), this, SLOT(onPopupMsgTimerEvent()));

    m_pPopupWindow = new PopupWindow(0, Qt::Window);
    Qt::WindowFlags flags;
    flags |= Qt::WindowStaysOnTopHint;
    //flags |= Qt::X11BypassWindowManagerHint;
    m_pPopupWindow->setWindowFlags(flags);

    m_p25Window = new TwFiveScreen(0, Qt::Window);
    m_p25Window->setWindowFlags(flags);

    connect(m_pPopupWindow, SIGNAL(closed()), this, SLOT(onPopupClosed()));

    QApplication::setWindowIcon(QIcon(":/images/lt_main_icon.png"));

    createActions();
    createTrayIcon();

    m_pTrayIcon->show();

    if (!Document::getInstance()->isDataBaseFileExists()) {
        QMessageBox::warning(m_pPopupWindow, tr("Warning"), tr("Could not load data base file."));
    }
}

MainClass::~MainClass()
{
    delete m_pPopupTimer;
    delete m_pPopupMsgTimer;
}

// init functions

void MainClass::createActions()
{
    m_pEnablePopupAction = new QAction(tr("Popup Learning"), this);
    m_pEnablePopupAction->setCheckable(true);
    m_pEnablePopupAction->setChecked(Document::getInstance()->getIsEnablePopup());
    connect(m_pEnablePopupAction, SIGNAL(triggered()), this, SLOT(onEnablePopupAction()));

    m_pEnableToolTipMessagesAction = new QAction(tr("ToolTips Learning"), this);
    m_pEnableToolTipMessagesAction->setCheckable(true);
    m_pEnableToolTipMessagesAction->setChecked(Document::getInstance()->getIsEnableToolTipMessages());
    connect(m_pEnableToolTipMessagesAction, SIGNAL(triggered()), this, SLOT(onEnableToolTipMessagesAction()));

    m_pShowTaskAction = new QAction(tr("Show Task"), this);
    connect(m_pShowTaskAction, SIGNAL(triggered()), this, SLOT(onShowTask()));

    m_pAddWordsAction = new QAction(tr("Add Words"), this);
    connect(m_pAddWordsAction, SIGNAL(triggered()), this, SLOT(onAddWords()));

    m_pSettingsAction = new QAction(tr("Preferences"), this);
    connect(m_pSettingsAction, SIGNAL(triggered()), this, SLOT(onSettings()));

    m_pExitAction = new QAction(tr("Exit"), this);
    connect(m_pExitAction, SIGNAL(triggered()), this, SLOT(onExit()));

    m_pAboutAction = new QAction(tr("About"), this);
    connect(m_pAboutAction, SIGNAL(triggered()), this, SLOT(onAbout()));

    m_p25ModeAction = new QAction(tr("25 Mode"), this);
    // Disabled action until it is not implemented
    m_p25ModeAction->setEnabled(false);
    connect(m_p25ModeAction, SIGNAL(triggered()), this, SLOT(on25Mode()));
}

void MainClass::createTrayIcon()
{
    m_pTrayIconMenu = new QMenu();
    m_pTrayIconMenu->addAction(m_pEnablePopupAction);
    m_pTrayIconMenu->addAction(m_pEnableToolTipMessagesAction);
    m_pTrayIconMenu->addSeparator();
    m_pTrayIconMenu->addAction(m_pShowTaskAction);
    m_pTrayIconMenu->addAction(m_pAddWordsAction);
    m_pTrayIconMenu->addAction(m_pSettingsAction);
    m_pTrayIconMenu->addAction(m_pAboutAction);
    m_pTrayIconMenu->addSeparator();
    // m_pTrayIconMenu->addAction(m_p25ModeAction);
    m_pTrayIconMenu->addSeparator();
    m_pTrayIconMenu->addAction(m_pExitAction);

    m_pTrayIcon = new QSystemTrayIcon(this);
    m_pTrayIcon->setContextMenu(m_pTrayIconMenu);
    m_pTrayIcon->setIcon(QIcon(":/images/lt_main_icon.png"));
}

// application

void MainClass::onPopupTimerEvent()
{
    if (Document::getInstance()->getIsEnablePopup() && Document::getInstance()->isTaskDataAvailable()) {
	showPopupTask();
    }
}

// protected slots

void MainClass::onShowTask()
{
    if (!Document::getInstance()->isTaskDataAvailable()) {
        QMessageBox::warning(m_pPopupWindow, tr("Warning"), tr("No data available!\nPlease make sure that data base is loaded and at least one not empty word set is selected."));
    } else {
        showPopupTask();
    }
}

void MainClass::onAddWords()
{
    AddNewWordsDialog dlg;
    dlg.exec();
}

void MainClass::onSettings()
{
    SettingsDialog dlg;
    dlg.exec();
    m_pPopupTimer->stop();
    m_pPopupTimer->start(Document::getInstance()->getPopupInterval() * TIME_FORMAT);

    m_pPopupMsgTimer->stop();
    m_pPopupMsgTimer->start(Document::getInstance()->getMessagePopupInterval() * TIME_FORMAT);
}

void MainClass::on25Mode()
{
    if (Document::getInstance()->isTaskDataAvailable() && !m_p25Window->isVisible()) {
        m_p25Window->showFullScreen();
    }
}

void MainClass::onPopupClosed()
{
    if (m_pPopupTimer->isActive()) {
        m_pPopupTimer->stop();
    }
    m_pPopupTimer->start(Document::getInstance()->getPopupInterval() * TIME_FORMAT);
}

void MainClass::onPopupMsgTimerEvent()
{
    if (Document::getInstance()->isTaskDataAvailable()
            && Document::getInstance()->getIsEnableToolTipMessages()
            && !m_pPopupWindow->isVisible() && !m_pTrayIconMenu->isVisible()) {
        showMessage();
    }
}

void MainClass::onEnablePopupAction()
{
    Document::getInstance()->getIsEnablePopup() = m_pEnablePopupAction->isChecked();
}

void MainClass::onEnableToolTipMessagesAction()
{
    Document::getInstance()->getIsEnableToolTipMessages() = m_pEnableToolTipMessagesAction->isChecked();
}

void MainClass::onExit()
{
    Document::removeInstance();
    qApp->quit();
}

void MainClass::onAbout()
{
    QMessageBox::about(m_pTrayIconMenu, tr("About"), tr("<b>Language Teacher</b><br />version 0.0.9<br /><br />Anatolii Kyryliuk"));
}

// public functions

void MainClass::showPopupTask()
{
    if (!m_pPopupWindow->isVisible() && !m_pTrayIconMenu->isVisible()) {
        m_pPopupWindow->setWordGroup(Document::getInstance()->getRandomWordGroup());
        m_pPopupWindow->showFullScreen();
    }
}

void MainClass::showMessage()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(0);
    WordGroup wg = Document::getInstance()->getRandomWordGroup();
    QString message = wg.first;
    message += " - ";
    message += wg.second;
    m_pTrayIcon->showMessage(tr("learning..."), message, icon,
            Document::getInstance()->getMessageDurationInterval() * TIME_FORMAT);
}
