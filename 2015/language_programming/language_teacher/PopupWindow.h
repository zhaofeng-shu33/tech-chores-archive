#include <QWidget>

#include "Document.h"


namespace Ui
{
    class PopupWindow;
}

class QCloseEvent;
class QShowEvent;
class QPaintEvent;
class QTimer;

class PopupWindow : public QWidget
{
    Q_OBJECT
public:
    PopupWindow();
    PopupWindow(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual ~PopupWindow();
protected:
    Ui::PopupWindow* m_pWindow;
    
    QString m_strOriginal;
    QString m_strTranslated;

    QPixmap* m_pDesktopPixmap;
    QColor m_darkeningColor;

    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    bool verify();
    void clearEdits();
    void setAssignmentLabelTest();
    
public slots:
    void showFullScreen();

protected slots:
    void onCheckBtnClicked();
    void onFocusChanged(QWidget *old, QWidget *now);
    void onOriginalEditReturnPressed();
    void onTranslatedEditReturnPressed();
    void closeDialog();

signals:
    void closed();
    
public:
    void setWordGroup(WordGroup wordGroup);
};
