#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include<QtGui/QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
class FindDialog: public QDialog{
    Q_OBJECT
public:
    FindDialog();
    ~FindDialog();
/*signals:
    void FindPrevious(QString st, Qt::CaseSensitivity cs);
    void FindNext(QString st, Qt::CaseSensitivity cs);
*/
private:
    QLabel* label;
    QCheckBox* box1;
    QCheckBox* box2;
    QLineEdit* lineEdit;
    QPushButton* findButton;
    QPushButton* closeButton;
private slots:
   // void FindClicked();
   // void FindTriggerBox1();
   // void FindTriggerBox2();

    void EnableFindButton(QString text);

};

#endif // FINDDIALOG_H
