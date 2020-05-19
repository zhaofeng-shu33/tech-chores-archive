#include <QApplication>
#include <QDebug>
#include <QTextEdit>
#include <QTextCursor>
int main(int argc,char* argv[]){
    QApplication a(argc, argv);
    QTextEdit* te=new QTextEdit();
    QTextCursor tc = te->textCursor();
    tc.insertText("haben");
    tc.movePosition(QTextCursor::Left);
    tc.insertText("sein ");
    te->show();


    return a.exec();
}
