#ifndef __H_DOCUMENT__
#define __H_DOCUMENT__

#include <QString>
#include <QPair>
#include <QSize>
#include <QStringList>


class QStandardItemModel;
class QStandardItem;
class XmlManager;
class QSettings;

enum E_TEACHER_MODE {LEARNING_BOTH_WAYS = 0, LEARNING_ORIGINAL, LEARNING_TRANSLATED, TESTING_ORIGINAL, TESTING_TRANSLATED};
const int TIME_FORMAT = 60000;  // minutes
const int M_SEC_25_MODE = 40;
enum E_COLUMN_INDEX {E_PRIORITY_INDEX = 0, E_LANG_ORIGINAL_INDEX, E_ORIGINAL_INDEX, E_LANG_TRANSLATED_INDEX, E_TRANSLATED_INDEX,
                     // this value should always be the last
                     E_COLUMN_COUNT};

enum E_COLUMN_INDEX_ {E_FIRST_WORD_INDEX = 1};

enum E_SETTINGS_GROUP_INDEX {E_SETTINGS_BEHAVIOUR = 0, E_SETTINGS_APPEARANCE, E_SETTINGS_TWFIVE};

typedef QPair <QString, QString> WordGroup;

class Document : QObject
{
private:
    Document();
    ~Document();

    static Document* m_pInstance;

    QStandardItemModel *m_pWordsModel;
    XmlManager *m_pXmlManager;
    QString m_dbFilePath;

    QStandardItemModel *m_pCurrentSetsModel;
    QStringList m_currentSetsList;
    QString m_currentOriginalLanguage;
    QString m_currentTranslatedLanguage;

    // TODO: add to resources
    QString m_learningAssignmentText;
    QString m_learningOriginalAssignmentText;
    QString m_learningTranslatedAssignmentText;
    QString m_examingOriginalAssignmentText;
    QString m_examingTranslatedAssignmentText;

    int m_pPopupTimerInterval;
    int m_pPopupTimerIntervalFrom;
    int m_pPopupTimerIntervalTo;
    int m_defaultPriority;

    float m_messageDurationInterval;
    float m_messageTimerInterval;

    bool m_isEnablePopup;
    bool m_isEnableToolTipMessages;

    bool m_bIsRandomPopupTime;
    E_TEACHER_MODE m_eTeacherMode;

    QSize m_addWordsDialogSize;
    QSize m_settingsDialogSize;
    bool m_isAutosavingEnabled;

    void readSettings();
    void saveSettings();

    QStandardItem *addNewWordToItem(QStandardItem* set, int rowIndex, QString word, QString lang);

public:
    static Document* getInstance();
    static void removeInstance();

    void saveModelToXml();
    WordGroup getRandomWordGroup();

    QStandardItemModel *getModel(bool updateFromXml = false);
    XmlManager *getXmlManager();
    QStandardItemModel *getCurrentSetsModel();
    QStringList& getCurrentSetsList();
    QString& getOriginalLanguage();
    QString& getTranslatedLanguage();
    int getPopupInterval();
    int &getPopupIntervalStatic();
    QString& getDbFilePath();
    E_TEACHER_MODE &getMode();
    QString getAssignment();
    int &getPopupTimerIntervalFrom();
    int &getPopupTimerIntervalTo();
    bool &getIsRandomPopupTime();
    bool &getIsEnablePopup();
    bool &getIsEnableToolTipMessages();
    QString getModeStr();
    bool addNewLanguageToModel(QString lang);
    bool addNewSetToModel(QString set);
    QStandardItem *addNewWordsToModel(QString set, QString wOrig, QString wTransl, QString lOrig, QString lTransl);

    QSize &getAddWordsDialogSize();
    QSize &getSettingsDialogSize();
    bool &getIsAutosavingEnabled();

    float &getMessageDurationInterval();
    float &getMessagePopupInterval();

    bool isTaskDataAvailable();
    bool isDataBaseFileExists();
};


#endif // __H_DOCUMENT__
