#include "Document.h"
#include "XmlManager.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDir>
#include <QSettings>
#include <QDebug>

// windows compiler needs it
#include "time.h"


Document* Document::m_pInstance = 0;

// protected functions

Document::Document() : m_pWordsModel(0),
m_pXmlManager(0),
m_pCurrentSetsModel(0)
{
    qsrand((unsigned int)time(0));

    readSettings();

    // TODO: read from resources
    m_learningAssignmentText = "Write original and translated words:";
    m_learningOriginalAssignmentText = "Write original word and remember translated one:";
    m_learningTranslatedAssignmentText = "Write translated word and remember original one:";
    m_examingOriginalAssignmentText = "Translate into the original language:";
    m_examingTranslatedAssignmentText = "Translate into the language chosen:";

    m_defaultPriority = 5;
}

Document::~Document()
{
    saveSettings();
}

Document* Document::getInstance()
{
    if (!m_pInstance)
        m_pInstance = new Document();
    return m_pInstance;
}

void Document::removeInstance()
{
    delete m_pInstance;
}

void Document::readSettings()
{
    QSettings settings(QString("QtApps"), QString("LanguageTeacher"));
    settings.beginGroup("WindowsGeometry");
    m_addWordsDialogSize = settings.value("AddWordsDialogSize").toSize();
    m_settingsDialogSize = settings.value("SettingsDialogSize").toSize();
    settings.endGroup();

    settings.beginGroup("Timers");
    m_pPopupTimerInterval = settings.value("PopupTimerInterval", 10).toInt();
    m_pPopupTimerIntervalFrom = settings.value("PopupTimerIntervalFrom", 10).toInt();
    m_pPopupTimerIntervalTo = settings.value("PopupTimerIntervalTo", 10).toInt();
    m_messageDurationInterval = settings.value("MessageDurationInterval", 0.1).toDouble();
    m_messageTimerInterval = settings.value("MessageTimerInterval", 0.1).toDouble();
    m_bIsRandomPopupTime = settings.value("IsRandomPopupTime", true).toBool();
    m_isEnablePopup = settings.value("IsEnablePopup", true).toBool();
    m_isEnableToolTipMessages = settings.value("IsEnableToolTipMessages", true).toBool();
    settings.endGroup();

    settings.beginGroup("DataBase");
    // TODO: uncomment when change db path possibility is added
    // m_dbFilePath = settings.value("DbFilePath", QDir::currentPath() + "/LTDataBase.xml").toString();
    m_dbFilePath = QDir::currentPath() + "/lt_db.xml";
    m_isAutosavingEnabled = settings.value("IsAutosavingEnabled", true).toBool();
    settings.endGroup();

    settings.beginGroup("Languages");
    QString currSetsStr;
    currSetsStr = settings.value("CurSets", "set").toString();
    getCurrentSetsList() = currSetsStr.split(",");

    m_currentOriginalLanguage = settings.value("CurOriginalLanguage", "en").toString();
    m_currentTranslatedLanguage = settings.value("CurTranslatedLanguage", "ua").toString();
    m_eTeacherMode = static_cast <E_TEACHER_MODE> (settings.value("TeacherMode", LEARNING_BOTH_WAYS).toInt());
    settings.endGroup();
}

void Document::saveSettings()
{
    QSettings settings(QString("QtApps"), QString("LanguageTeacher"));
    settings.beginGroup("WindowsGeometry");
    settings.setValue("AddWordsDialogSize", m_addWordsDialogSize);
    settings.setValue("SettingsDialogSize", m_settingsDialogSize);
    settings.endGroup();

    settings.beginGroup("Timers");
    settings.setValue("PopupTimerInterval", m_pPopupTimerInterval);
    settings.setValue("PopupTimerIntervalFrom", m_pPopupTimerIntervalFrom);
    settings.setValue("PopupTimerIntervalTo", m_pPopupTimerIntervalTo);
    settings.setValue("MessageDurationInterval", m_messageDurationInterval);
    settings.setValue("MessageTimerInterval", m_messageTimerInterval);
    settings.setValue("IsRandomPopupTime", m_bIsRandomPopupTime);
    settings.setValue("IsEnablePopup", m_isEnablePopup);
    settings.setValue("IsEnableToolTipMessages", m_isEnableToolTipMessages);
    settings.endGroup();

    settings.beginGroup("DataBase");
    // TODO: uncomment when change db path possibility is added
    // settings.setValue("DbFilePath", m_dbFilePath);
    settings.setValue("IsAutosavingEnabled", m_isAutosavingEnabled);
    settings.endGroup();

    settings.beginGroup("Languages");
    // current sets
    QString currSetsStr;
    foreach (QString s, m_currentSetsList) {
        currSetsStr.append(s);
        currSetsStr.append(",");
    }
    // remove last comma
    currSetsStr.resize(currSetsStr.size() - 1);
    settings.setValue("CurSets", currSetsStr);

    settings.setValue("CurOriginalLanguage", m_currentOriginalLanguage);
    settings.setValue("CurTranslatedLanguage", m_currentTranslatedLanguage);
    settings.setValue("TeacherMode", m_eTeacherMode);
    settings.endGroup();
}

//  public functions

void Document::saveModelToXml()
{
    getXmlManager()->saveToXml(getModel());
}

WordGroup Document::getRandomWordGroup()
{
    QPair <QString, QString> displayPair;
    QStringList origWordsList;
    QStringList translWordsList;

    getModel();
    int origLanIndex = -1;
    int translLanIndex = -1;
    for (int i = E_PRIORITY_INDEX; i < m_pWordsModel->columnCount(); ++i) {
        if (m_pWordsModel->horizontalHeaderItem(i)->text() == m_currentOriginalLanguage) {
            origLanIndex = i;
        }
        if (m_pWordsModel->horizontalHeaderItem(i)->text() == m_currentTranslatedLanguage) {
            translLanIndex = i;
        }
    }

    int childRowIndex;
    // loop sets
    for (int i = 0; i < m_pWordsModel->rowCount(); ++i) {
        childRowIndex = 0;
        QStandardItem *setItem = m_pWordsModel->item(i, 0);
        // check whether set item is one of the currnet sets
        if (getCurrentSetsList().contains(setItem->text()) && setItem->rowCount() > 0) {
            // loop word items of the sets
            while (setItem->child(childRowIndex) != 0) {
                if (setItem->child(childRowIndex, origLanIndex) != 0
                    && setItem->child(childRowIndex, translLanIndex) != 0) {
                    origWordsList << setItem->child(childRowIndex, origLanIndex)->text();
                    translWordsList << setItem->child(childRowIndex, translLanIndex)->text();
                }
                ++childRowIndex;
            }
        }
    }
    if (!origWordsList.isEmpty()) {
        int randomIndex = qrand() % origWordsList.size();
        displayPair.first = origWordsList[randomIndex];
        displayPair.second = translWordsList[randomIndex];
    }
    return displayPair;
}

// public properties

QStandardItemModel *Document::getModel(bool updateFromXml)
{
    if (updateFromXml || !m_pWordsModel) {
        if (m_pWordsModel) {
            delete m_pWordsModel;
        }
        m_pWordsModel = new QStandardItemModel(0, E_FIRST_WORD_INDEX, this);
        m_pWordsModel->setHeaderData(E_PRIORITY_INDEX, Qt::Horizontal, QVariant("Priority"));
        getXmlManager()->readFromXml(m_pWordsModel);
    }
    return m_pWordsModel;
}

XmlManager *Document::getXmlManager()
{
    if (!m_pXmlManager) {;
        m_pXmlManager = new XmlManager();
    }
    return m_pXmlManager;
}

QStandardItemModel *Document::getCurrentSetsModel()
{
    // TODO:
    return 0;
}

QStringList& Document::getCurrentSetsList()
{
    return m_currentSetsList;
}

QString& Document::getOriginalLanguage()
{
    return m_currentOriginalLanguage;
}

QString& Document::getTranslatedLanguage()
{
    return m_currentTranslatedLanguage;
}

int &Document::getPopupIntervalStatic()
{
	return m_pPopupTimerInterval;
}

int Document::getPopupInterval()
{
    if (!m_bIsRandomPopupTime) {
        return m_pPopupTimerInterval;
    } else {
        return (qrand() % (m_pPopupTimerIntervalTo - m_pPopupTimerIntervalFrom + 1)) + m_pPopupTimerIntervalFrom;
    }
}

QString& Document::getDbFilePath()
{
    return m_dbFilePath;
}

E_TEACHER_MODE &Document::getMode()
{
    return m_eTeacherMode;
}

QString Document::getAssignment()
{
    if (m_eTeacherMode == LEARNING_BOTH_WAYS) {
        return m_learningAssignmentText;
    } else if (m_eTeacherMode == LEARNING_ORIGINAL) {
        return m_learningOriginalAssignmentText;
    } else if (m_eTeacherMode == LEARNING_TRANSLATED) {
        return m_learningTranslatedAssignmentText;
    } else if (m_eTeacherMode == TESTING_ORIGINAL) {
        return m_examingOriginalAssignmentText;
    } else if (m_eTeacherMode == TESTING_TRANSLATED) {
        return m_examingTranslatedAssignmentText;
    }
    return QString();
}

QString Document::getModeStr()
{
    switch (m_eTeacherMode) {
    case LEARNING_BOTH_WAYS:
        return tr("learning both ways...");
    break;
    case LEARNING_ORIGINAL:
        return tr("learning original...");
    break;
    case LEARNING_TRANSLATED:
        return tr("learning translated...");
    break;
    case TESTING_ORIGINAL:
        return tr("testing original...");
    break;
    case TESTING_TRANSLATED:
        return tr("testing translated...");
    break;
    default:
        return QString();
    break;
    }
}

int &Document::getPopupTimerIntervalFrom()
{
    return m_pPopupTimerIntervalFrom;
}

int &Document::getPopupTimerIntervalTo()
{
    return m_pPopupTimerIntervalTo;
}

bool &Document::getIsRandomPopupTime()
{
    return m_bIsRandomPopupTime;
}

float &Document::getMessageDurationInterval()
{
    return m_messageDurationInterval;
}

float &Document::getMessagePopupInterval()
{
    return m_messageTimerInterval;
}

QSize &Document::getAddWordsDialogSize()
{
    return m_addWordsDialogSize;
}

QSize &Document::getSettingsDialogSize()
{
    return m_settingsDialogSize;
}

bool &Document::getIsEnablePopup()
{
    return m_isEnablePopup;
}

bool &Document::getIsEnableToolTipMessages()
{
    return m_isEnableToolTipMessages;
}

bool &Document::getIsAutosavingEnabled()
{
    return m_isAutosavingEnabled;
}

bool Document::isTaskDataAvailable()
{
    bool returnValue = false;
    getModel();
    int childRowIndex = 0;
    for (int i = 0; i < m_pWordsModel->rowCount(); ++i) {
        childRowIndex = 0;
        QStandardItem *setItem = m_pWordsModel->item(i, 0);
        if (getCurrentSetsList().contains(setItem->text()) && setItem->rowCount() > 0) {
            returnValue = true;
            break;
        }
    }
    return returnValue;
}

bool Document::isDataBaseFileExists()
{
    return QFile::exists(m_dbFilePath);
}

bool Document::addNewLanguageToModel(QString lang)
{
    bool isExists = false;

    for (int i = E_PRIORITY_INDEX; i < m_pWordsModel->columnCount(); ++i) {
        if (m_pWordsModel->horizontalHeaderItem(i)->text() == lang) {
            isExists = true;
        }
    }
    if (!isExists) {
        int newIndex = m_pWordsModel->columnCount();
        m_pWordsModel->setHorizontalHeaderItem(newIndex, new QStandardItem(lang));
    }

    return isExists;
}

bool Document::addNewSetToModel(QString set)
{
    bool isExists = false;

    int rowsCount = m_pWordsModel->rowCount();
    if (m_pWordsModel->findItems(set).isEmpty()) {
        QStandardItem *item = new QStandardItem(set);
        m_pWordsModel->setItem(rowsCount, 0, item);
    } else {
        isExists = true;
    }

    return isExists;
}

QStandardItem *Document::addNewWordsToModel(QString set, QString wOrig, QString wTransl, QString lOrig, QString lTransl)
{
    // find set where words will be added to
    QStandardItem *parent;
    if (m_pWordsModel->findItems(set).isEmpty()) {
        addNewSetToModel(set);
    }
    parent = m_pWordsModel->findItems(set).at(0);

    int childRowIndex = 0;
    QStandardItem* item = 0;

    bool isExists = false;
    // loop word items of the set
    while ((item = parent->child(childRowIndex)) != 0) {
        // loop columns (languages)
        for (int i = E_PRIORITY_INDEX; i < m_pWordsModel->columnCount(); ++i) {
            // qDebug() << parent->child(childRowIndex, i)->text();
            // check whether word is exists for that language
            if (parent->child(childRowIndex, i)) {
                if ((parent->child(childRowIndex, i)->text() == wOrig && m_pWordsModel->horizontalHeaderItem(i)->text() == lOrig)
                    || (parent->child(childRowIndex, i)->text() == wTransl && m_pWordsModel->horizontalHeaderItem(i)->text() == lTransl)) {
                    isExists = true;
                    break;
                }
            }
        }
        if (isExists) {
            break;
        }
        ++childRowIndex;
    }
    // if there is no such word
    if (!isExists) { // add new word item to set
        parent->setRowCount(parent->rowCount() + 1);
        childRowIndex = parent->rowCount() - 1;
    }
    QStandardItem* retWordItem = 0;
    retWordItem = addNewWordToItem(parent, childRowIndex, wOrig, lOrig);
    addNewWordToItem(parent, childRowIndex, wTransl, lTransl);
    return retWordItem;
}

QStandardItem *Document::addNewWordToItem(QStandardItem* set, int rowIndex, QString word, QString lang)
{
    QStandardItem* retWordItem = 0;
    addNewLanguageToModel(lang);
    // loop columns (languages)
    for (int i = E_PRIORITY_INDEX; i < m_pWordsModel->columnCount(); ++i) {
        if (m_pWordsModel->horizontalHeaderItem(i)->text() == lang) {
            QString priorityText;
            priorityText.setNum(m_defaultPriority);
            if (!set->child(rowIndex, i)) {
                // add word item
                QStandardItem *newItem = new QStandardItem();
                newItem->setText(word);
                set->setChild(rowIndex, i, newItem);
                // add priority item
                newItem = new QStandardItem();
                // TODO: add possibility to add priority
                newItem->setText(priorityText);
                set->setChild(rowIndex, E_PRIORITY_INDEX, newItem);
            } else {
                set->child(rowIndex, i)->setText(word);
                set->child(rowIndex, E_PRIORITY_INDEX)->setText(priorityText);
            }
            retWordItem = set->child(rowIndex, i);
        }
    }
    return retWordItem;
}
