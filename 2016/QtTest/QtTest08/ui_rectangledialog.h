/********************************************************************************
** Form generated from reading UI file 'rectangledialog.ui'
**
** Created: Tue Dec 8 19:25:27 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLEDIALOG_H
#define UI_RECTANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectangleDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lengthEdit;
    QLineEdit *widthEdit;
    QLineEdit *rectangleAreaEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *calculateButton;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RectangleDialog)
    {
        if (RectangleDialog->objectName().isEmpty())
            RectangleDialog->setObjectName(QString::fromUtf8("RectangleDialog"));
        RectangleDialog->resize(400, 300);
        widget = new QWidget(RectangleDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(13, 80, 104, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        widget1 = new QWidget(RectangleDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(120, 80, 135, 101));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lengthEdit = new QLineEdit(widget1);
        lengthEdit->setObjectName(QString::fromUtf8("lengthEdit"));

        verticalLayout_2->addWidget(lengthEdit);

        widthEdit = new QLineEdit(widget1);
        widthEdit->setObjectName(QString::fromUtf8("widthEdit"));

        verticalLayout_2->addWidget(widthEdit);

        rectangleAreaEdit = new QLineEdit(widget1);
        rectangleAreaEdit->setObjectName(QString::fromUtf8("rectangleAreaEdit"));

        verticalLayout_2->addWidget(rectangleAreaEdit);

        widget2 = new QWidget(RectangleDialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(260, 80, 77, 100));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        calculateButton = new QPushButton(widget2);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setEnabled(false);
        calculateButton->setDefault(true);

        verticalLayout_3->addWidget(calculateButton);

        closeButton = new QPushButton(widget2);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout_3->addWidget(closeButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lengthEdit);
        label_2->setBuddy(widthEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lengthEdit, widthEdit);
        QWidget::setTabOrder(widthEdit, rectangleAreaEdit);
        QWidget::setTabOrder(rectangleAreaEdit, calculateButton);
        QWidget::setTabOrder(calculateButton, closeButton);

        retranslateUi(RectangleDialog);

        QMetaObject::connectSlotsByName(RectangleDialog);
    } // setupUi

    void retranslateUi(QWidget *RectangleDialog)
    {
        RectangleDialog->setWindowTitle(QApplication::translate("RectangleDialog", "Calculate the area of Rectangle", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RectangleDialog", "Rectangle &Length", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RectangleDialog", "Rectangle &Width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RectangleDialog", "Area", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("RectangleDialog", "Calculate", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("RectangleDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RectangleDialog: public Ui_RectangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEDIALOG_H
