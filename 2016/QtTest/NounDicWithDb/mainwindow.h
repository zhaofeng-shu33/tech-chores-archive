#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
class QAction;
class QLabel;
class wordInput;
class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
  MainWindow();
protected:
  void closeEvent(QCloseEvent* event);
  private slots:
    bool save();
    bool saveAs();
    void open();
    void newFile();
    void updateStatusBar();
    /*void find();
    void about();
    void openRecentFile();
    void spreadsheetModified();*/
private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
  //  void readSettings();
    wordInput* wordinput;
    QLabel* locationLabel;
    QAction* newAction;
    enum{ MaxRecentFiles=5 };
    QAction* recentFileActions[MaxRecentFiles];
    QAction* openAction,*saveAction,*saveAsAction,*exitAction,*aboutAction;
    QMenu* fileMenu,*editMenu,*toolsMenu,*optionsMenu,*helpMenu;
    QAction* cutAction,*copyAction,*pasteAction;
    QToolBar *fileToolBar,*editToolBar;
  };

#endif // MAINWINDOW_H
