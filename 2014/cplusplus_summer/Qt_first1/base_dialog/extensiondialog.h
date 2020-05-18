#ifndef EXTENTIONDIALOG_H
#define EXTENTIONDIALOG_H
class ExtensionDialog : public QDialog
{
    Q_OBJECT

public:
    ExtensionDialog();
    void InitialBaseInformation();

private:
    QWidget* baseWidget;
   
};

#endif // EXTENTIONDIALOG_H
