/********************************************************************************
** Form generated from reading UI file 'scalabledialog.ui'
**
** Created: Tue Dec 8 22:25:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALABLEDIALOG_H
#define UI_SCALABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScalableDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_8;

    void setupUi(QDialog *ScalableDialog)
    {
        if (ScalableDialog->objectName().isEmpty())
            ScalableDialog->setObjectName(QString::fromUtf8("ScalableDialog"));
        ScalableDialog->resize(468, 300);
        gridLayout_3 = new QGridLayout(ScalableDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        primaryGroupBox = new QGroupBox(ScalableDialog);
        primaryGroupBox->setObjectName(QString::fromUtf8("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primaryGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(primaryGroupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 2, 1);

        label_2 = new QLabel(primaryGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(primaryGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);


        gridLayout_3->addWidget(primaryGroupBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(ScalableDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        closeButton = new QPushButton(ScalableDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(ScalableDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_3->addLayout(verticalLayout, 0, 2, 3, 1);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(ScalableDialog);
        secondaryGroupBox->setObjectName(QString::fromUtf8("secondaryGroupBox"));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(secondaryGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(secondaryGroupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 0, 1, 1, 1);

        checkBox = new QCheckBox(secondaryGroupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 1, 0, 1, 2);

        checkBox_9 = new QCheckBox(secondaryGroupBox);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        gridLayout_2->addWidget(checkBox_9, 1, 2, 1, 1);

        checkBox_2 = new QCheckBox(secondaryGroupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 2, 0, 1, 1);

        checkBox_6 = new QCheckBox(secondaryGroupBox);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_2->addWidget(checkBox_6, 2, 2, 1, 1);

        checkBox_4 = new QCheckBox(secondaryGroupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 3, 0, 1, 2);

        checkBox_7 = new QCheckBox(secondaryGroupBox);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        gridLayout_2->addWidget(checkBox_7, 3, 2, 1, 1);

        checkBox_3 = new QCheckBox(secondaryGroupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 4, 0, 1, 2);

        checkBox_10 = new QCheckBox(secondaryGroupBox);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        gridLayout_2->addWidget(checkBox_10, 4, 2, 1, 1);

        checkBox_5 = new QCheckBox(secondaryGroupBox);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_2->addWidget(checkBox_5, 5, 0, 1, 2);

        checkBox_8 = new QCheckBox(secondaryGroupBox);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        gridLayout_2->addWidget(checkBox_8, 5, 2, 1, 1);


        gridLayout_3->addWidget(secondaryGroupBox, 2, 0, 1, 2);

        QWidget::setTabOrder(comboBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_9);
        QWidget::setTabOrder(checkBox_9, checkBox_6);
        QWidget::setTabOrder(checkBox_6, checkBox_7);
        QWidget::setTabOrder(checkBox_7, checkBox_10);
        QWidget::setTabOrder(checkBox_10, checkBox_8);
        QWidget::setTabOrder(checkBox_8, okButton);
        QWidget::setTabOrder(okButton, closeButton);
        QWidget::setTabOrder(closeButton, moreButton);

        retranslateUi(ScalableDialog);
        QObject::connect(okButton, SIGNAL(clicked()), ScalableDialog, SLOT(accept()));
        QObject::connect(closeButton, SIGNAL(clicked()), ScalableDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(ScalableDialog);
    } // setupUi

    void retranslateUi(QDialog *ScalableDialog)
    {
        ScalableDialog->setWindowTitle(QApplication::translate("ScalableDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        primaryGroupBox->setTitle(QApplication::translate("ScalableDialog", "Content Finding", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScalableDialog", "Content", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ScalableDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ScalableDialog", "Choice", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ScalableDialog", "Distinguish Full/Half Width", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ScalableDialog", "Find", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("ScalableDialog", "Close", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("ScalableDialog", "&More", 0, QApplication::UnicodeUTF8));
        secondaryGroupBox->setTitle(QApplication::translate("ScalableDialog", "Search Items", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ScalableDialog", "Search", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("ScalableDialog", "All", 0, QApplication::UnicodeUTF8)
        );
        checkBox->setText(QApplication::translate("ScalableDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231(&H\357\274\211", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("ScalableDialog", "\345\214\272\345\210\206\345\211\215\347\274\200(&X)", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("ScalableDialog", "\345\205\250\345\255\227\345\214\271\351\205\215(&Y)", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("ScalableDialog", "\345\214\272\345\210\206\345\220\216\347\274\200(&Y)", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("ScalableDialog", "\344\275\277\347\224\250\351\200\232\351\205\215\347\254\246(&U)", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("ScalableDialog", "\345\214\272\345\210\206\345\205\250/\345\215\212\350\247\222(&M)", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("ScalableDialog", "\345\220\214\351\237\263(\350\213\261\346\226\207\357\274\211(&K)", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("ScalableDialog", "\345\277\275\347\225\245\346\240\207\347\202\271\347\254\246\345\217\267(&S)", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("ScalableDialog", "\346\237\245\346\211\276\345\215\225\350\257\215\347\232\204\346\211\200\346\234\211\345\275\242\345\274\217(\350\213\261\346\226\207)(&W)", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("ScalableDialog", "\345\277\275\347\225\245\347\251\272\346\240\274(&A)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScalableDialog: public Ui_ScalableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALABLEDIALOG_H
