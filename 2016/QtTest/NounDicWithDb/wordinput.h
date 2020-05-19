#ifndef WORDINPUT_H
#define WORDINPUT_H
#include <QWidget>
#include <QtSql>
#include <QStandardItemModel>
#include <phonon/MediaObject>
#include <QStandardItem>
#include <QList>
#include <QCompleter>
#include <QMap>
#include <QPair>
#include <QXmlQuery>
typedef QPair<int,int> pair_type;

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
   // QSqlDatabase db;
  //  QSqlQueryModel* model;
    QStandardItemModel showmodel,wordlist;
    QByteArray record_uncompressed;
    QCompleter* completer;
    QDir* dir;
    Phonon::MediaObject *music;
    void seek_word(QString);
    int ToInteger(QByteArray array);
    qint64 ToLongInteger(QByteArray array);
    void LoadData();
    QMap<QString,pair_type> m_map;
    QXmlQuery query;
private slots:
    void on_webView_loadProgress(int progress);
    void on_listView_clicked(QModelIndex index);
    void on_pushButton_clicked();
    void on_lineEdit_editingFinished();
    void on_comboBox_currentIndexChanged(int index );

};

#endif // WORDINPUT_H
