#include <QtGui>
#include <QApplication>
#include <QTextCodec>

#include "StyleMainWindow.h"

#include "CustomStyle.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// 设置tr的字符编码
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));

	//CCustomStyle* st = new CCustomStyle;
	//app.setStyle(st);
	//CUIStyleDlg::instance()->iniUIStyle();

	Q_INIT_RESOURCE(Texture);


//	app.setStyle(new CCustomStyle(":/background/45.png", ":/background/17.png"));
        app.setStyle(new CCustomStyle());

     /*   {
                // 调色板
                QPalette palette = QPalette();//QColor(52, 52, 52));
                palette.setBrush(QPalette::BrightText, Qt::green);
                palette.setBrush(QPalette::Base, QColor(52, 52, 52));
                palette.setBrush(QPalette::Highlight, QColor(0, 60, 0));
                palette.setBrush(QPalette::Text, QColor(0, 255, 0));
                palette.setBrush(QPalette::ButtonText, QColor(0, 255, 0));
                palette.setBrush(QPalette::WindowText, QColor(0, 255, 0));
// 
// 		/// 画刷
                palette.setBrush(QPalette::Button, Qt::black);
                palette.setBrush(QPalette::Light, QColor(0, 85, 0));
                palette.setBrush(QPalette::Mid, Qt::black);
                palette.setBrush(QPalette::Midlight, Qt::black);
                palette.setBrush(QPalette::Dark,  QColor(0, 85, 0));
                palette.setBrush(QPalette::Shadow, Qt::black);
                palette.setBrush(QPalette::Window, Qt::black);
// 
                QBrush brush = palette.base();
// 
// 		// 设置调色板
                palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
                palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
// 
                app.setPalette(palette);
// 
       // }
*/
	CStyleMainWindow smw;
	smw.show();

	return app.exec();
}
