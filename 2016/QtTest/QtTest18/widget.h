#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDomDocument>
#include <QTreeWidgetItem>
#include <QHash>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool Initialize();

private:
    Ui::Widget *ui;
    QDomDocument domDocument;
    QHash<QTreeWidgetItem *, QDomElement> domElementForItem;
    void parseFolderElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0);
    QTreeWidgetItem *createItem(const QDomElement &element,
                                QTreeWidgetItem *parentItem = 0);


};

#endif // WIDGET_H
