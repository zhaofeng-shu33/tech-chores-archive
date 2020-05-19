#include "textedit.h"
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>

TextEdit::TextEdit(QString fileName,QWidget *parent)
: QTextEdit(parent), c(0)
{
    setCompleter(fileName);
   // connect(this,SIGNAL(textChanged()),this,SLOT(GetTextUnderCursor()));
    connect(c,SIGNAL(activated(QString)),this,SLOT(insertCompletion(QString)));
    connect(this,SIGNAL(textUnderCursor(QString)),c,SLOT(setCompletionPrefix(QString)));
    connect(this,SIGNAL(AskForAppendNewWord(QString)),c,SLOT(appendNew(QString)));
    //  c->installEventFilter(this);
}

TextEdit::~TextEdit(){
}
/*bool TextEdit::eventFilter(QObject *obj, QEvent *event){
    if(obj==GerCompleter){
       // if(event->type()==QEvent::KeyPress)
    }
}*/

void TextEdit::setCompleter(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly|QFile::Text))
        return;
    QStringList words;
    QTextStream out(&file);
    out.setCodec("UTF-8");
    while (!out.atEnd())
        words.append(out.readLine());

    file.close();

    c=new GerCompleter(words,this);
    if (!c)
        return;

   //qDebug()<<c->completionModel()->data(c->completionModel()->index(1,0)).toString();
//    QObject::connect(c, SIGNAL(activated(QString)),
 //                    this, SLOT(insertCompletion(QString)));
}

void TextEdit::insertCompletion(const QString& completion)
{
 //   qDebug()<<"Insert Completion";
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
    this->setFocus();
}

void TextEdit::keyPressEvent(QKeyEvent *e)
{  
   if(Qt::Key_Return != e->key())
    QTextEdit::keyPressEvent(e);//filter return press

   const bool ctrlOrShift = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);
   static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
   bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;

   if ((e->text().length()!=0&&eow.contains(e->text()))||Qt::Key_Escape ==e->key()||(ctrlOrShift && e->text().isEmpty())||hasModifier){
       if((Qt::Key_Return==e->key()))qDebug()<<"Return pressed!";
       c->popup()->hide();
        return;
    }
   if (Qt::Key_Return == e->key()){
       if(c->popup()->isVisible()) c->activateReturnMatchedPattern(c->popup()->currentIndex());
       else {
           this->textCursor().insertText("\n");
           emit textUnderCursor("");
           int dir=0;
           if (Qt::Key_Down==e->key())dir++;
           else if(Qt::Key_Up==e->key()&&(!c->popup()->isHidden()))dir--;
           AskForComplete(dir);
       }
       return;
    }
   QTextCursor tc=this->textCursor();
   tc.select(QTextCursor::WordUnderCursor);
   if(tc.selectedText()==""){
       if(previousWord.length()>=7&&previousWord.isSimpleText()){
       qDebug()<<"One new Word added: "<<previousWord;
       emit this->AskForAppendNewWord(previousWord);
        }
       return;
   }
   previousWord = tc.selectedText();
   if(previousWord.length() < 3){
       c->popup()->hide();
       return;
   }

    emit textUnderCursor(previousWord);
    int dir=0;
    if (Qt::Key_Down==e->key())dir++;
    else if(Qt::Key_Up==e->key()&&(!c->popup()->isHidden()))dir--;
    AskForComplete(dir);
}
void TextEdit::AskForComplete(int dir){
    QPoint p(0, height());
    int x = mapToGlobal(p).x();
    int y = mapToGlobal(p).y() + 1;
    c->complete(QPoint(x,y),dir); // popup it up!

}


