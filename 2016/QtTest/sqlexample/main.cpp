#include <QtGui>
#include <QtSql>
#include <QDebug>

int main(int argc,char* argv[]){
    QApplication app(argc,argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("datenbankserver.example.com");
    db.setDatabaseName("D:/PythonDemo/example.db");
    if(!db.open()){
        qDebug()<<db.lastError();
        return 1;
    }
    QSqlQuery query(db);
     /*   bool bsuccess=query.exec("create table person(id int primary key,firstname varchar(20),major varchar(20))");
        if(!bsuccess)
    {
        qDebug()<<query.lastError();
    }
    else{
        qDebug()<<"table created";
    }*/
//    query.exec("delete from person where id=101");

    int max_id=0;
    query.prepare("select rowid from WordList");
    if(!query.exec()) qDebug()<<query.lastError();
    else while(query.next()){
        max_id=query.value(0).toInt();
        qDebug()<<QString("maximum id: %1").arg(max_id);
    }
    // query.exec("insert into person values (1,'Denny','Physics')");
   /* query.prepare("insert into person values (?,?,?)");
    query.addBindValue(max_id+1);
    query.addBindValue("Guo Kelvin");
    query.addBindValue("Transportation");
    if(!query.exec())qDebug()<<query.lastError();
    else qDebug()<<"inserted";

    query.prepare("update person set firstname=:name where id=:id");
    query.bindValue(":name","Guo Kevin");
    query.bindValue(":id",3);
    if(!query.exec()) qDebug()<<query.lastError();
    else qDebug()<<"updated!";
    if(!query.exec("select * from person"))
        qDebug()<<query.lastError();
    else while(query.next()){
        int id=query.value(0).toInt();
        QString name=query.value(1).toString();
        QString major=query.value(2).toString();
        qDebug()<<QString("id:%1 name:%2 major %3").arg(id).arg(name).arg(major);
    }
    QSqlTableModel *model=new QSqlTableModel;
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTreeView *trv=new QTreeView;
    trv->setModel(model);
    trv->show();
    db.close();
    *///QFile::remove()
    return app.exec();
}
