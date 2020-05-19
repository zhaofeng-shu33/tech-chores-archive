#ifndef __H_MAIN_CLASS__
#define __H_MAIN_CLASS__


#include <QObject>


class QTimer;
class QSystemTrayIcon;
class QMenu;
class QAction;
class QStandardItemModel;

class PopupWindow;
class TwFiveScreen;
class SettingsDialog;


class MainClass : public QObject
{
	Q_OBJECT;
public:
    MainClass();
    ~MainClass();

    void showPopupTask();
    void showMessage();

protected:
    QTimer *m_pPopupTimer;
    QTimer *m_pPopupMsgTimer;

    PopupWindow* m_pPopupWindow;
    TwFiveScreen* m_p25Window;

    unsigned int m_pPopupTimerInterval;

    void createActions();
    void createTrayIcon();

    QSystemTrayIcon *m_pTrayIcon;
    QMenu *m_pTrayIconMenu;

    QAction* m_pShowTaskAction;
    QAction* m_pAddWordsAction;
    QAction* m_pSettingsAction;
    QAction* m_p25ModeAction;
    QAction* m_pEnablePopupAction;
    QAction* m_pEnableToolTipMessagesAction;
    QAction* m_pAboutAction;
    QAction* m_pExitAction;

protected slots:
    void onShowTask();
    void onAddWords();
    void onSettings();
    void on25Mode();
    void onPopupClosed();
    void onEnablePopupAction();
    void onEnableToolTipMessagesAction();
    void onExit();
    void onAbout();

    void onPopupTimerEvent();
    void onPopupMsgTimerEvent();
};


#endif // __H_MAIN_CLASS__
