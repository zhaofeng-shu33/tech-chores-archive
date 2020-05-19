#include <QWidget>
#include <QGraphicsTextItem>
#include "Document.h"


namespace Ui
{
    class TwFiveForm;
}

class QTimer;
class QCloseEvent;

class TwFiveScreen : public QWidget
{
    Q_OBJECT
public:
    TwFiveScreen();
    TwFiveScreen(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual ~TwFiveScreen();

    void setWordGroup(WordGroup wordGroup);

protected:
    Ui::TwFiveForm* m_pWindow;

    QGraphicsScene *m_pScene;

    QGraphicsTextItem *m_pOriginItem;
    QGraphicsTextItem *m_pTranslatedItem;

    QFont m_itemsFont;

    QTimer *m_p25_Timer;

    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

protected slots:
    void on25_TimerEvent();
};
