#include <QUiLoader>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include "textfinder.h"
TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent)
{
    QWidget *formWidget=this->loadUiFile();
    ui_pushButton =qFindChild<QPushButton*>(this, "pushButton");
    this->ui_lineEdit=qFindChild<QLineEdit*>(this,"lineEdit");
    ui_textEdit=qFindChild<QTextEdit*>(this,"textEdit");
    QMetaObject::connectSlotsByName(this);
    loadTextFile();
    this->isFirstTime=true;
    this->setWindowTitle("Text Finder");
    QVBoxLayout *layout = new QVBoxLayout;
       layout->addWidget(formWidget);
       setLayout(layout);
}

TextFinder::~TextFinder()
{
}
QWidget* TextFinder::loadUiFile()
 {
     QUiLoader loader;

     QFile file(":/form/textfinder.ui");
     file.open(QFile::ReadOnly);

     QWidget *formWidget = loader.load(&file, this);
     file.close();

     return formWidget;
 }
void TextFinder::loadTextFile()
 {
     QFile inputFile(":/form/input.txt");
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);
     QString line = in.readAll();
     inputFile.close();

     ui_textEdit->append(line);
     ui_textEdit->setUndoRedoEnabled(false);
     ui_textEdit->setUndoRedoEnabled(true);
 }
void TextFinder::on_pushButton_clicked()
{
    QString searchString = ui_lineEdit->text();
    QTextDocument *document = ui_textEdit->document();

    bool found = false;

    if (isFirstTime == false)
        document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                "The search field is empty. Please enter a word and click Find.");
    } else {

        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString,highlightCursor, QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                       QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        isFirstTime = false;

                if (found == false) {
                    QMessageBox::information(this, tr("Word Not Found"),
                        "Sorry, the word cannot be found.");
                }
            }
        }
