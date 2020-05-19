#include<QtGui>
#include "wordinput.h"
#include "mainwindow.h"
MainWindow::MainWindow(){
   wordinput=new wordInput;
   setCentralWidget(wordinput);
   createActions();
   createMenus();
   createContextMenu();
   createToolBars();
   createStatusBar();

}
bool MainWindow::save(){
   return true;
}

bool MainWindow::saveAs(){
   return true;
}

void MainWindow::open(){

}

void MainWindow::newFile(){

}
void MainWindow::closeEvent(QCloseEvent *event){
}

void MainWindow::createActions(){
    newAction=new QAction("New",this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setStatusTip("Create a new file");
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
    openAction=new QAction("Open",this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setStatusTip("open a new file");
    connect(newAction,SIGNAL(triggered()),this,SLOT(open()));
    saveAction=new QAction("Save",this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setStatusTip("save existing file");
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
    saveAsAction=new QAction("SaveAs",this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip("save the file in another place");
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));
    exitAction=new QAction("Exit",this);
    exitAction->setShortcut(Qt::CTRL + Qt::Key_Q);
    exitAction->setStatusTip("Exit the application");
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    aboutAction=new QAction("About Qt",this);
    aboutAction->setStatusTip("Show the Qt Library's About box");
    connect(aboutAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    cutAction=new QAction("Cut",this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    copyAction=new QAction("Copy",this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    pasteAction=new QAction("Paste",this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));

}
void MainWindow::createMenus(){
    fileMenu=menuBar()->addMenu("&File");
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(exitAction);

    editMenu=menuBar()->addMenu("&Edit");
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    toolsMenu=menuBar()->addMenu("&Tools");
    optionsMenu=menuBar()->addMenu("&Options");
    menuBar()->addSeparator();
    helpMenu=menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAction);
}
void MainWindow::createContextMenu(){
    wordinput->addAction(cutAction);
    wordinput->addAction(copyAction);
    wordinput->addAction(pasteAction);
    wordinput->setContextMenuPolicy(Qt::ActionsContextMenu);
}
void MainWindow::createToolBars(){
    fileToolBar=addToolBar("&File");
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar=addToolBar("&Edit");
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
}
void MainWindow::createStatusBar(){
    statusBar()->showMessage("Hello");
    updateStatusBar();
}
void MainWindow::updateStatusBar(){

}
