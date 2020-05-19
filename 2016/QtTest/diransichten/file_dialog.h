#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <QDialog>
class QModelIndex;
class QDirModel;
class QItemSelectionModel;
namespace Ui {
    class File_Dialog;
}

class File_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit File_Dialog(QWidget *parent = 0);
    ~File_Dialog();

private:
    QItemSelectionModel *selModel;
    QDirModel *dirModel;
    Ui::File_Dialog *ui;
protected slots:
    void switchToDir(const QModelIndex& index){};
    void switchView(){};
};

#endif // FILE_DIALOG_H
