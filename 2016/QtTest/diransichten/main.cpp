#include <QtGui>
#include "file_dialog.h"
int main(int argc,char* argv[]){
    QWidget w;
    QDirModel dirModel;
    w.setWindowTitle("Four directory views using one model");
    QGridLayout* lay=new QGridLayout(&w);
    QListView* lv=new QListView;
    lay->addWidget(lv,0,0);
    lv->setModel(&dirModel);
    lv->setViewMode(QListView::IconMode);
    QTreeView *trv=new QTreeView;
    lay->addWidget(trv,0,1);
    trv->setModel(&dirModel);
    QTableView *tav=new QTableView;
    tav->setModel(&dirModel);
    lay->addWidget(tav,1,0);
    QModelIndex cwdIndex=dirModel.index("D:/C++/graphics programming"); //let the model refer to the data
    lv->setRootIndex(cwdIndex);
    trv->setRootIndex(cwdIndex);
    tav->setRootIndex(cwdIndex);
    w.show();
    QApplication app(argc,argv);

  /*  File_Dialog my_file_dialog;
    my_file_dialog.show();*/
    return app.exec();
}
