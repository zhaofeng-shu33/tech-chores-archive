#ifndef GERCOMPLETER_H
#define GERCOMPLETER_H

#include <QObject>
#include <QModelIndex>
#include <QListView>
class QMouseEvent;
class QStringListModel;
class QStringList;
class QPoint;
class GerCompleter : public QObject
{
    Q_OBJECT
public:
    explicit GerCompleter(QStringList wordList,QObject *parent = 0);
    QString completionPrefix(){return CompletionPrefix;}
    QListView* popup(){return CompletionView;}
    void activateReturnMatchedPattern(QModelIndex modelIndex);
    void complete(QPoint cr,int dir);
    QStringList GetWordList(){return wordList;}
    void AcceptWordList(QStringList wordList_new){
        wordList=wordList_new;
    }
protected:
    //void mousePressEvent(QMouseEvent *event);
signals:
    void activated(const QString& text);
public slots:
    void setCompletionPrefix(QString Prefix);
    void ReturnMatchedPattern(QModelIndex modelIndex);
    void appendNew(QString word);
private:
    void LoadCompletionView();
    QStringList wordList;
    QListView* CompletionView;
    QString CompletionPrefix;
    int currentSelection;
};

#endif // GERCOMPLETER_H
