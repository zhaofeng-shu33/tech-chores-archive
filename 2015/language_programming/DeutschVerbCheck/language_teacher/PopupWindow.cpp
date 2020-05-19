#include "PopupWindow.h"
#include "ui_PopupWindow.h"

#include <QCloseEvent>
#include <QShowEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QDesktopWidget>


PopupWindow::PopupWindow()
{
}

PopupWindow::PopupWindow(QWidget * parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    m_pDesktopPixmap = new QPixmap();
    m_darkeningColor = QColor(0, 0, 0, 100);

    m_pWindow = new Ui::PopupWindow();
    m_pWindow->setupUi(this);
    
    connect(m_pWindow->checkButton, SIGNAL(clicked()), this, SLOT(onCheckBtnClicked()));
    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)), this, SLOT(onFocusChanged(QWidget *, QWidget *)));
    connect(m_pWindow->origWordLineEdit, SIGNAL(returnPressed()), this, SLOT(onOriginalEditReturnPressed()));
    connect(m_pWindow->translatedWordLineEdit, SIGNAL(returnPressed()), this, SLOT(onTranslatedEditReturnPressed()));
}

PopupWindow::~PopupWindow()
{
    delete m_pDesktopPixmap;
}

// protected functions

void PopupWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    hide();
    clearEdits();
    emit closed();
}

bool PopupWindow::verify()
{
    // TODO: ignore odd spaces and word explanations in brackets

    QStringList originalList = m_strOriginal.split(",");
    QStringList translatedList = m_strTranslated.split(",");
    QStringList ansveredListOriginal;
    QStringList ansveredListTranslated;
    bool reVal = true;
    E_TEACHER_MODE mode = Document::getInstance()->getMode();
    // loop list of ansvered words and check if original list contains each of them
    if (mode == LEARNING_BOTH_WAYS || mode == TESTING_ORIGINAL || mode == LEARNING_ORIGINAL) {
        ansveredListOriginal = m_pWindow->origWordLineEdit->text().split(",");
        foreach (QString str, ansveredListOriginal) {
            if (!originalList.contains(str)) {
                reVal = false;
            }
        }
    }
    // if mode is LEARNING_BOTH_WAYS - condition of both ifs will be true and ansvered lists
    // of original and translated words will be checked
    // loop list of translated words and check if original list contains each of them
    if (mode == LEARNING_BOTH_WAYS || mode == TESTING_TRANSLATED || mode == LEARNING_TRANSLATED) {
        ansveredListTranslated = m_pWindow->translatedWordLineEdit->text().split(",");
        foreach (QString str, ansveredListTranslated) {
            if (!translatedList.contains(str)) {
                reVal = false;
            }
        }
    }
    return reVal;
}

void PopupWindow::clearEdits()
{
    m_pWindow->origWordLineEdit->clear();
    m_pWindow->translatedWordLineEdit->clear();
}

void PopupWindow::setAssignmentLabelTest()
{
    m_pWindow->assignmentLabel->setText(Document::getInstance()->getAssignment());
}

// protected slots

void PopupWindow::onCheckBtnClicked()
{
    if (verify()) {
        m_pWindow->assignmentLabel->setText("Correct answer!");
        m_pWindow->appleLabel->setPixmap(QPixmap(":/images/green_apple.png"));
        QTimer::singleShot(200, this, SLOT(closeDialog()));
    } else {
        m_pWindow->assignmentLabel->setText("Incorrect answer!");
        m_pWindow->appleLabel->setPixmap(QPixmap(":/images/red_apple.png"));
    }
}

void PopupWindow::setWordGroup(WordGroup wordGroup)
{
    m_strOriginal = wordGroup.first;
    m_strTranslated = wordGroup.second;
    m_pWindow->origWordLabel->setText(m_strOriginal);
    m_pWindow->translatedWordLabel->setText(m_strTranslated);
}

void PopupWindow::onOriginalEditReturnPressed()
{
    if (Document::getInstance()->getMode() == TESTING_ORIGINAL
        || Document::getInstance()->getMode() == LEARNING_ORIGINAL) {
        onCheckBtnClicked();
    } else if (Document::getInstance()->getMode() == LEARNING_BOTH_WAYS) {
        if (m_pWindow->translatedWordLineEdit->text().isEmpty()) {
            m_pWindow->translatedWordLineEdit->setFocus(Qt::TabFocusReason);
        } else {
            onCheckBtnClicked();
        }
    }
}

void PopupWindow::onTranslatedEditReturnPressed()
{
    onCheckBtnClicked();
}

void PopupWindow::closeDialog()
{
    hide();
    clearEdits();
    m_pWindow->appleLabel->setPixmap(QPixmap(":/images/grey_apple.png"));
    emit closed();
}

// public slots

void PopupWindow::showFullScreen()
{
    m_pWindow->origWordLineEdit->setFocus();
    QWidget::showFullScreen();
}

void PopupWindow::onFocusChanged(QWidget *old, QWidget *now)
{
    Q_UNUSED(old);
    // TODO: add authomated languages switching
    if (now == m_pWindow->origWordLineEdit) {
        /*QLocale currentLocale(Document::getInstance()->getOriginalLanguage());
        QLocale::setDefault(currentLocale);*/
        // QEvent e(QEvent::LanguageChange);
    } else if (now == m_pWindow->translatedWordLineEdit) {
        /*QLocale currentLocale(Document::getInstance()->getTranslatedLanguage());
        QLocale::setDefault(currentLocale);*/
    }
}

void PopupWindow::showEvent(QShowEvent *event)
{
    setAssignmentLabelTest();
    *m_pDesktopPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    m_pWindow->answerFrame->setVisible(true);
    if (Document::getInstance()->getMode() == TESTING_TRANSLATED) {
        m_pWindow->translatedWordCaption->setVisible(true);
        m_pWindow->translatedWordLineEdit->setVisible(true);
        m_pWindow->translatedWordLabel->setVisible(false);
        m_pWindow->origWordLabel->setVisible(true);
        m_pWindow->origWordLineEdit->setVisible(false);
        m_pWindow->originWordCaption->setVisible(false);
    } else if (Document::getInstance()->getMode() == TESTING_ORIGINAL) {
        m_pWindow->origWordLabel->setVisible(false);
        m_pWindow->translatedWordCaption->setVisible(false);
        m_pWindow->translatedWordLineEdit->setVisible(false);
        m_pWindow->translatedWordLabel->setVisible(true);
        m_pWindow->origWordLineEdit->setVisible(true);
        m_pWindow->originWordCaption->setVisible(true);
    } else if (Document::getInstance()->getMode() == LEARNING_ORIGINAL) {
        m_pWindow->translatedWordCaption->setVisible(false);
        m_pWindow->translatedWordLineEdit->setVisible(false);
        m_pWindow->translatedWordLabel->setVisible(true);
        m_pWindow->origWordLabel->setVisible(true);
        m_pWindow->origWordLineEdit->setVisible(true);
        m_pWindow->originWordCaption->setVisible(true);
    } else if (Document::getInstance()->getMode() == LEARNING_TRANSLATED) {
        m_pWindow->translatedWordCaption->setVisible(true);
        m_pWindow->translatedWordLineEdit->setVisible(true);
        m_pWindow->translatedWordLabel->setVisible(true);
        m_pWindow->origWordLabel->setVisible(true);
        m_pWindow->origWordLineEdit->setVisible(false);
        m_pWindow->originWordCaption->setVisible(false);
    } else {
        m_pWindow->translatedWordCaption->setVisible(true);
        m_pWindow->translatedWordLineEdit->setVisible(true);
        m_pWindow->translatedWordLabel->setVisible(true);
        m_pWindow->origWordLabel->setVisible(true);
        m_pWindow->origWordLineEdit->setVisible(true);
        m_pWindow->originWordCaption->setVisible(true);
    }
    m_pWindow->modeLabel->setText(Document::getInstance()->getModeStr());
    QWidget::showEvent(event);
}

void PopupWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if (m_pDesktopPixmap && !m_pDesktopPixmap->isNull()) {
        p.drawPixmap(this->rect(), *m_pDesktopPixmap, m_pDesktopPixmap->rect());
        p.fillRect(this->rect(), m_darkeningColor);
    }
    QWidget::paintEvent(event);
}

void PopupWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        close();
    }
    QWidget::keyPressEvent(event);
}
