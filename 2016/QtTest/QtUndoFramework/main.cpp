#include "undotest.h"
#include <QtGui/QApplication>
#include <QWindowsStyle>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle(new QWindowsStyle());
    {
                // 调色板
                QPalette palette = QPalette(QColor(52, 52, 52));
                palette.setBrush(QPalette::BrightText, QColor(255,0,255));
                palette.setBrush(QPalette::Base, QColor(52, 52, 52));
                palette.setBrush(QPalette::Highlight, QColor(255, 0, 0));//Red
                palette.setBrush(QPalette::Text, Qt::blue);
                palette.setBrush(QPalette::ButtonText, Qt::yellow);//
                palette.setBrush(QPalette::WindowText, QColor(0, 255, 0));//green

    // 		/// 画刷
    // 		palette.setBrush(QPalette::Button, Qt::black);
    // 		palette.setBrush(QPalette::Light, QColor(0, 85, 0));
    // 		palette.setBrush(QPalette::Mid, Qt::black);
    // 		palette.setBrush(QPalette::Midlight, Qt::black);
    // 		palette.setBrush(QPalette::Dark,  QColor(0, 85, 0));
    // 		palette.setBrush(QPalette::Shadow, Qt::black);
    // 		palette.setBrush(QPalette::Window, Qt::black);
    //
    // 		QBrush brush = palette.base();
    //
    // 		// 设置调色板
    // 		palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
    // 		palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
    // 		palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
    // 		palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
    // 		palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
    // 		palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
    //
                app.setPalette(palette);

        }

    undoTest w;
    w.show();
    return app.exec();
}
