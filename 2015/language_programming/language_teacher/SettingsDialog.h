#ifndef __H_SETTING_DIALOG__
#define __H_SETTING_DIALOG__


#include "ui_SettingsDialog.h"
#include <QDialog>


class QAbstractButton;
class QCloseEvent;


class SettingsDialog : public QDialog , private Ui::SettingsDlg
{
    Q_OBJECT
public:
    SettingsDialog( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    virtual ~SettingsDialog();

protected:
    void initData();
    void resizeEvent(QResizeEvent * event);

protected slots:
    void on_buttonBox_accepted();
    void on_staticTimeButton_clicked();
    void on_randomTimeButton_clicked();
    void on_popupIntervalFromSpinBox_valueChanged(int);
    void on_popupIntervalToSpinBox_valueChanged(int);
    void onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
};


#endif // __H_SETTING_DIALOG__
