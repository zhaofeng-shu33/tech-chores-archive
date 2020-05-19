#include <QApplication>
#include <QTextEdit>
#include <QTextBlock>
#include <QTextDocument>
#include <QTextTable>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit *editor=new QTextEdit;
    QTextDocument* editorDocument=editor->document();
    QTextFrame *root=editorDocument->rootFrame();
    QTextBlock block = editorDocument->firstBlock();
    QTextCursor blockCursor(block);
    QTextCharFormat myTextCharFormat;
    myTextCharFormat.setFontUnderline(1);
    myTextCharFormat.setUnderlineStyle(QTextCharFormat::SingleUnderline);
    myTextCharFormat.setUnderlineColor(Qt::red);
    blockCursor.insertText("LineOne",myTextCharFormat);
    QTextCursor frameCursor(root);
    QTextTableFormat myTextTableFormat;
    myTextTableFormat.setCellPadding(4);
    QTextTable* textTable=frameCursor.insertTable(6,2,myTextTableFormat);
    for(int i=0;i<textTable->rows();i++)
        for(int j=0;j<textTable->columns();j++){
            QTextTableCell tableCell=textTable->cellAt(i,j);
            tableCell.firstCursorPosition().insertText("Guten");
    }
    editor->show();

    return a.exec();
}

