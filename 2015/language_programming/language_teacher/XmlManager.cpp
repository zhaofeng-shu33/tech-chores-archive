#include "XmlManager.h"
#include "Document.h"

#include <QStandardItemModel>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QStringList>
#include <QDir>
#include <QDebug>


XmlManager::XmlManager()
{
}

XmlManager::~XmlManager()
{
}

void XmlManager::saveToXml(QStandardItemModel* model)
{
    QFile file(Document::getInstance()->getDbFilePath());
    file.open(QIODevice::ReadWrite);

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("root");
    for (int i = 0; i < model->rowCount(); ++i) {

        QStandardItem *setItem = model->item(i, 0);

        if (setItem != 0) {

            stream.writeStartElement("set");
            stream.writeAttribute("name", setItem->text());

            for (int row = 0; row < setItem->rowCount(); ++row) {
                stream.writeStartElement("wordgroup");
                stream.writeAttribute("priority", setItem->child(row, E_PRIORITY_INDEX)->text());

                for (int lanHeaderIndex = E_FIRST_WORD_INDEX; lanHeaderIndex < model->columnCount(); ++lanHeaderIndex) {

                    if (setItem->child(row, lanHeaderIndex)) {
                        // if there is data (word) for this language
                        stream.writeStartElement("language");
                        stream.writeAttribute("name", model->horizontalHeaderItem(lanHeaderIndex)->text());

                        QStringList words = setItem->child(row, lanHeaderIndex)->text().split(QString(","));
                        foreach (QString word, words) {
                            stream.writeTextElement("word", word);
                        }
                        stream.writeEndElement(); // language
                    }
                }

                stream.writeEndElement(); // wordgroup

            }
            stream.writeEndElement(); // set
        }
    }

    stream.writeEndElement(); // root
    stream.writeEndElement(); // bookmark

    stream.writeEndDocument();
    file.close();
}

QStandardItemModel* XmlManager::readFromXml(QStandardItemModel* model)
{
    QFile file(Document::getInstance()->getDbFilePath());
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader stream(&file);

    while(!stream.atEnd()) {
        // root index
        stream.readNext();
        while (stream.readNext() == QXmlStreamReader::StartElement && stream.name() == "set") {

            QStandardItem *setItem = new QStandardItem(stream.attributes().at(0).value().toString());
            model->setItem(model->rowCount(), 0, setItem);

            // read wordgroups
            stream.readNext();
            int wordGroupIndex = 0;
            while (stream.readNext() == QXmlStreamReader::StartElement && stream.name() == "wordgroup") {
                // read priority
                setItem->setChild(wordGroupIndex, new QStandardItem(stream.attributes().at(0).value().toString()));

                // read languages
                stream.readNext();
                while (stream.readNext() == QXmlStreamReader::StartElement && stream.name() == "language") {
                    // read language
                    QString language = stream.attributes().at(0).value().toString();
                    int headerLangItemIndex = -1;
                    // find header item
                    for (int i = 0; i < model->columnCount(); ++i) {
                        if (model->horizontalHeaderItem(i)->text() == language) {
                            headerLangItemIndex = i;
                            break;
                        }
                    }

                    // add new language item if there is no that language in header
                    if (headerLangItemIndex == -1) {
                        headerLangItemIndex = model->columnCount();
                        model->setHorizontalHeaderItem(headerLangItemIndex, new QStandardItem(language));
                    }

                    // set word to that item
                    stream.readNext();
                    QString words;
                    while (stream.readNext() == QXmlStreamReader::StartElement) {
                        if (!words.isEmpty())
                            words += ",";
                        // read word
                        words += stream.readElementText();

                        stream.readNext();
                    }
                    // list << new QStandardItem(words);
                    setItem->setChild(wordGroupIndex, headerLangItemIndex, new QStandardItem(words));
                    stream.readNext();
                }
                stream.readNext();
                ++wordGroupIndex;
            }
            stream.readNext();
        }
    }
    file.close();
    return model;
}

QStringList XmlManager::getSetList()
{
    QFile file(Document::getInstance()->getDbFilePath());
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader stream(&file);

    QStringList list;
    while(!stream.atEnd()) {
        if (stream.readNext() == QXmlStreamReader::StartElement && stream.name() == "set") {
            list << stream.attributes().at(0).value().toString();
        }
    }
    file.close();
    list.removeDuplicates();
    return list;
}

QStringList XmlManager::getLanguageList()
{
    QFile file(Document::getInstance()->getDbFilePath());
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader stream(&file);

    QStringList list;
    while(!stream.atEnd()) {
        if (stream.readNext() == QXmlStreamReader::StartElement && stream.name() == "language") {
            list << stream.attributes().at(0).value().toString();
        }
    }
    file.close();
    list.removeDuplicates();
    return list;
}
