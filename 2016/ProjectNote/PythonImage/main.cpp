#include <QImage>
#include <QDebug>
#include <iostream>
#include <fstream>
int max(int a,int b){
    if(a<b)return b;
    return a;
}
using namespace std;
int main(){

   QImage myImage1("D:\\ProjectNote\\PythonImage\\standard008.bmp");
  // std::ofstream fout("D:\\ProjectNote\\PythonImage\\data.txt");
   qDebug()<<myImage1.size();
   myImage1.setPixel(2,0,0);
   for(int i=0;i<myImage1.height();i++){
       for(int j=0;j<myImage1.width();j++){
           if(!myImage1.valid(i,j))qDebug()<<i<<' '<<j;
        if(myImage1.pixel(i,j))qDebug()<<myImage1.pixel(i,j);
    }
      //fout<<'\n'<<'\n';
   }
  // fout.close();
   /* QImage myImage2("D:\\ProjectNote\\PythonImage\\standard002.bmp");

     QImage myImage3(201,201,QImage::Format_Indexed8);
     qDebug()<<myImage3.height()<<' '<<myImage3.width()<<' ';

     QRgb value;
     for(int r=0;r<7;r++){
         int t=36*r;
         value = qRgb(t, t, t); // 0xff7aa327
         myImage3.setColor(r, value);
     }
     value = qRgb(255, 255, 255); // 0xffedba31
     myImage3.setColor(7, value);

       int d=20;
       for(int i=50;i<myImage3.height()-50;i++)
        for(int j=50;j<myImage3.width()-50;j++){
           float sum=2*qGray(myImage1.pixel(5*i,5*j))/255;
           for(int i1=5*i-d;i1<5*i+d;i1++)
            for(int j1=5*j-d;j1<5*j+d;j1++){
                if(i1!=5*i||j1!=5*j)
                    sum+=qGray(myImage1.pixel(i1,j1))*1.0/(max(abs(i1-5*i),abs(j1-5*j))*255);
            }
             myImage3.setPixel(i,j,int(sum*7/162));
                //if(sum*7/802>0)qDebug()<<sum*7/802;

    }
    QImage yourImage(4,4,QImage::Format_Mono);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            yourImage.setPixel(i,j,255);
  */
      qDebug()<<"SAVE: "<<myImage1.save("D:\\ProjectNote\\PythonImage\\standard008.bmp","BMP");
    system("pause");
    return 0;
}
