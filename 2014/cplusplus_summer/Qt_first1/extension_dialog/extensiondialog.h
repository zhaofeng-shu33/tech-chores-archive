#ifndef EXTENTIONDIALOG_H
#define EXTENTIONDIALOG_H
#include <QtGui>
#include <QDialog>
class ExtensionDialog : public QDialog
{
    Q_OBJECT

public:
    ExtensionDialog(QWidget *parent=0);
    void InitialBaseInformation();
    void InitialDetailInformation();
public slots:
    void SlotExtension();
private:
    QWidget* baseWidget;
    QWidget* detailWidget;
};

#endif // EXTENTIONDIALOG_H
