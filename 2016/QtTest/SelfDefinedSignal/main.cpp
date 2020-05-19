#include <QtGui/QApplication>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("D:\\PythonDemo\\wordform.txt");
    file.open(QFile::ReadOnly|QFile::Text);
    QStringList words;
    QTextStream out(&file);
    out.setCodec("UTF-8");
    while (!out.atEnd())
        words.append(out.readLine());
    QString CompletionPrefix="H";
    QStringList CompletionList=words.filter(QRegExp(QString("\\b%1.*").arg(CompletionPrefix)));
    qDebug()<<CompletionList.length();
    file.close();
    Widget w(words);
    w.show();
    return a.exec();
}
