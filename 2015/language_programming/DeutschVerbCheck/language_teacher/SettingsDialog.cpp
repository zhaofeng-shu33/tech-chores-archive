#include "SettingsDialog.h"
#include "Document.h"
#include "XmlManager.h"
#include <QDebug>

#include <QColorDialog>
#include <QPushButton>
#include <QCloseEvent>
#include <QLineEdit>


SettingsDialog::SettingsDialog( QWidget * parent, Qt::WindowFlags f) : QDialog(parent,f)
{
    setupUi(this);
    this->resize(Document::getInstance()->getSettingsDialogSize());

    QIcon i;
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(":/images/behaviour.png"), QString("Behaviour"));
    this->contentsListWidget->insertItem(E_SETTINGS_BEHAVIOUR, pItem);
    pItem = new QListWidgetItem(QIcon(":/images/appearance.png"), QString("View"));
    this->contentsListWidget->insertItem(E_SETTINGS_APPEARANCE, pItem);
    pItem = new QListWidgetItem(QIcon(":/images/25mode.png"), QString("25 Mode"));
    this->contentsListWidget->insertItem(E_SETTINGS_TWFIVE, pItem);
    this->contentsListWidget->setCurrentRow(E_SETTINGS_BEHAVIOUR);
    this->contentsListWidget->setIconSize(QSize(64, 64));

    modeComboBox->addItem(tr("Learning Both Ways"));
    modeComboBox->addItem(tr("Learning Original"));
    modeComboBox->addItem(tr("Learning Translated"));
    modeComboBox->addItem(tr("Testing Original"));
    modeComboBox->addItem(tr("Testing Translated"));

    connect(staticTimeButton, SIGNAL(clicked()), this, SLOT(on_staticTimeButton_clicked()));
    connect(randomTimeButton, SIGNAL(clicked()), this, SLOT(on_randomTimeButton_clicked()));
    connect(popupIntervalFromSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_popupIntervalFromSpinBox_valueChanged(int)));
    connect(popupIntervalToSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_popupIntervalToSpinBox_valueChanged(int)));
    connect(this->contentsListWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(onCurrentItemChanged(QListWidgetItem *, QListWidgetItem *)));

    initData();
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::on_buttonBox_accepted()
{
    Document::getInstance()->getMode() = static_cast <E_TEACHER_MODE> (modeComboBox->currentIndex());

    Document::getInstance()->getCurrentSetsList().clear();
    for (int i = 0; i < setsListWidget->count(); ++i) {
        QListWidgetItem *pItem = setsListWidget->item(i);
        if (pItem->checkState() == Qt::Checked) {
            Document::getInstance()->getCurrentSetsList().append(pItem->data(Qt::DisplayRole).toString());
        }
    }

    Document::getInstance()->getOriginalLanguage() = languageOriginalComboBox->currentText();
    Document::getInstance()->getTranslatedLanguage() = languageTranslatedComboBox->currentText();
    Document::getInstance()->getPopupIntervalStatic() = popupIntervalSpinBox->value();
    Document::getInstance()->getIsRandomPopupTime() = randomTimeButton->isChecked();
    Document::getInstance()->getPopupTimerIntervalFrom() = popupIntervalFromSpinBox->value();
    Document::getInstance()->getPopupTimerIntervalTo() = popupIntervalToSpinBox->value();
    Document::getInstance()->getMessagePopupInterval() = msgPopupIntervalDoubleSpinBox->value();
    Document::getInstance()->getMessageDurationInterval() = msgDurationIntervalDoubleSpinBox->value();
}

// protected functions

void SettingsDialog::resizeEvent(QResizeEvent * event)
{
    Document::getInstance()->getSettingsDialogSize() = this->size();
    QDialog::resizeEvent(event);
}

void SettingsDialog::initData()
{
    // init sets list
    setsListWidget->addItems(Document::getInstance()->getXmlManager()->getSetList());
    for (int i = 0; i < setsListWidget->count(); ++i) {
        QListWidgetItem *pItem = setsListWidget->item(i);
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        if (Document::getInstance()->getCurrentSetsList().contains(pItem->data(Qt::DisplayRole).toString()) ) {
            pItem->setCheckState(Qt::Checked);
        } else {
            pItem->setCheckState(Qt::Unchecked);
        }
    }

    languageOriginalComboBox->addItems(Document::getInstance()->getXmlManager()->getLanguageList());
    languageTranslatedComboBox->addItems(Document::getInstance()->getXmlManager()->getLanguageList());

    modeComboBox->setCurrentIndex(static_cast <int> (Document::getInstance()->getMode()));
    languageOriginalComboBox->setCurrentIndex(languageOriginalComboBox->findText(Document::getInstance()->getOriginalLanguage()));
    languageTranslatedComboBox->setCurrentIndex(languageTranslatedComboBox->findText(Document::getInstance()->getTranslatedLanguage()));
    bool isRandom = Document::getInstance()->getIsRandomPopupTime();
    popupIntervalSpinBox->setEnabled(!isRandom);
    randomTimeButton->setChecked(isRandom);
    staticTimeButton->setChecked(!isRandom);
    popupIntervalFromSpinBox->setEnabled(isRandom);
    popupIntervalToSpinBox->setEnabled(isRandom);
    popupIntervalSpinBox->setValue(Document::getInstance()->getPopupIntervalStatic());
    popupIntervalFromSpinBox->setValue(Document::getInstance()->getPopupTimerIntervalFrom());
    popupIntervalToSpinBox->setValue(Document::getInstance()->getPopupTimerIntervalTo());

    msgPopupIntervalDoubleSpinBox->setValue(Document::getInstance()->getMessagePopupInterval());
    msgDurationIntervalDoubleSpinBox->setValue(Document::getInstance()->getMessageDurationInterval());
}

void SettingsDialog::on_staticTimeButton_clicked()
{
    bool isRandom = randomTimeButton->isChecked();
    popupIntervalSpinBox->setEnabled(!isRandom);
    popupIntervalToSpinBox->setEnabled(isRandom);
    popupIntervalFromSpinBox->setEnabled(isRandom);
}

void SettingsDialog::on_randomTimeButton_clicked()
{
    bool isRandom = randomTimeButton->isChecked();
    popupIntervalSpinBox->setEnabled(!isRandom);
    popupIntervalToSpinBox->setEnabled(isRandom);
    popupIntervalFromSpinBox->setEnabled(isRandom);
}

void SettingsDialog::on_popupIntervalFromSpinBox_valueChanged(int value)
{
    if (value > popupIntervalToSpinBox->value()) {
       popupIntervalToSpinBox->setValue(value);
    }
}

void SettingsDialog::on_popupIntervalToSpinBox_valueChanged(int value)
{
    if (value < popupIntervalFromSpinBox->value()) {
        popupIntervalFromSpinBox->setValue(value);
    }
}

void SettingsDialog::onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);
    stackedWidget->setCurrentIndex(this->contentsListWidget->currentRow());
}
