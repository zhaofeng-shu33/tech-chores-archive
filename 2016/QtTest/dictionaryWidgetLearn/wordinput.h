#ifndef WORDINPUT_H
#define WORDINPUT_H
#include <QWidget>
#include <QtSql>
#include <QStandardItemModel>
#include <phonon/MediaObject>
#include <QStandardItem>
#include <QList>
#include <QCompleter>
namespace Ui {
    class wordInput;
}
class wordInput : public QWidget
{
    Q_OBJECT

public:
    explicit wordInput(QWidget *parent = 0);
    Ui::wordInput *ui;
    ~wordInput();


private:
    QSqlDatabase db;
    QSqlQueryModel* model;
    QStandardItemModel showmodel,wordlist;
    QCompleter* completer;
    QDir* dir;
    Phonon::MediaObject *music;
    void seek_word(QString);


private slots:
    void on_listView_clicked(QModelIndex index);
    void on_pushButton_clicked();
    void on_lineEdit_editingFinished();
    void on_comboBox_currentIndexChanged(int index );

};

#endif // WORDINPUT_H
