#ifndef SCALABLEDIALOG_H
#define SCALABLEDIALOG_H

#include <QDialog>
#include <ui_scalabledialog.h>
class scalabledialog : public QDialog,public Ui::ScalableDialog
{
    Q_OBJECT
public:
    explicit scalabledialog(QWidget *parent = 0);

signals:

private slots:
    void on_moreButton_clicked();
};

#endif // SCALABLEDIALOG_H
