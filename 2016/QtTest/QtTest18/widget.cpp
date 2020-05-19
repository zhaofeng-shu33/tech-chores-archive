#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"Initialize succeed: "<<Initialize();
}
bool Widget::Initialize(){
    QStringList labels;
    labels << tr("Sentence") << tr("Chinese");

    ui->treeWidget->setHeaderLabels(labels);


     QFile file(":/xml/Text6-2_a.xml");
     if(!file.exists()){
         qDebug()<<"xml File does not exist!";
         return false;
     }
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug()<<"Error to open the xml file!";
        return false;
     }
     QString errorStr;
     int errorLine;
     int errorColumn;

     if (!domDocument.setContent(&file, true, &errorStr, &errorLine,
                                 &errorColumn)) {
         QMessageBox::information(window(), tr("DOM Document"),
                                  tr("Parse error at line %1, column %2:\n%3")
                                  .arg(errorLine)
                                  .arg(errorColumn)
                                  .arg(errorStr));
         return false;
     }
     QDomElement root = domDocument.documentElement();
     if (root.tagName() != "text") {
         QMessageBox::information(window(), tr("DOM Document"),
                                  tr("The file is not an text xml file."));
         return false;
     } else if (root.hasAttribute("version")
         && root.attribute("version") != "1.0") {
        QMessageBox::information(window(), tr("DOM Document"),
                           tr("The file is not an xml version 1.0 "
                              "file."));
         return false;
    }
     ui->treeWidget->clear();
     QDomElement child = root.firstChildElement("body");
     while (!child.isNull()) {
         parseFolderElement(child);
         child = child.nextSiblingElement();
     }
     return true;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::parseFolderElement(const QDomElement &element, QTreeWidgetItem *parentItem){
    QDomElement paragraph = element.firstChildElement();
    while(!paragraph.isNull()){
        QTreeWidgetItem *item = createItem(element, parentItem);
        QString title = "paragraph";

        item->setFlags(item->flags() | Qt::ItemIsSelectable);
        item->setText(0, title);
        ui->treeWidget->setItemExpanded(item, 0);
        QDomElement child = paragraph.firstChildElement();
        while(!child.isNull()){
            if (child.tagName() == "s") {
                QTreeWidgetItem *childItem = createItem(child, item);

                QString germanSentence = child.firstChildElement("or").text();

                childItem->setFlags(item->flags() | Qt::ItemIsSelectable);
                childItem->setText(0, germanSentence);
                childItem->setText(1, child.firstChildElement("te").text());
            }

            child=child.nextSiblingElement();
        }
    paragraph=paragraph.nextSiblingElement();
    }
}
QTreeWidgetItem *Widget::createItem(const QDomElement &element, QTreeWidgetItem *parentItem){
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(ui->treeWidget);
    }
    domElementForItem.insert(item, element);
    return item;
}
