#include "ftpget.h"


FtpGet::FtpGet(QObject* parent): QObject(parent)
{
    connect(&ftp,SIGNAL(done(bool)),this,SLOT(ftpDone(bool)));
    connect(&ftp,SIGNAL(stateChanged(int)),this,SLOT(ftpCommandStarted(int)));
}
void FtpGet::ftpDone(bool error){
    if(error)std::cerr<<"Error: "<<ftp.errorString().toStdString()<<endl;
    else std::cout<<"File downloaded as "<<file.fileName().toStdString()<<endl;
    file.close();
    emit done();
}
bool FtpGet::getFile(QUrl url){
    QString localFileName= QFileInfo(url.path()).fileName();
    file.setFileName(localFileName);
    cout<<"localFileName"<<' '<<localFileName.toStdString()<<endl;
    if(!file.open(QIODevice::WriteOnly)) {
        std::cerr<<"Error:Can not Write File";
        return false;
    }
    connectedId=ftp.connectToHost(url.host(),url.port(21));
    loginId=ftp.login();
    getId=ftp.get(url.path(),&file);
    closeId=ftp.close();
    return true;
}
void FtpGet::ftpCommandStarted(int id){
    if(id==connectedId)cout<<"Connecting..."<<endl;
    else if(id==loginId)cout<<"Logging in..."<<endl;
    else if(id==getId)cout<<"Downloading..."<<endl;
    else if(id==closeId)cout<<"Downloading finished."<<endl;

}
