#include "AddNewWordsDialog.h"
#include "XmlManager.h"

#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTextStream>
#include <QDebug>
#include <QMenu>


AddNewWordsDialog::AddNewWordsDialog(QWidget * parent, Qt::WindowFlags f) : QDialog(parent, f)
{
    setupUi(this);
    this->resize(Document::getInstance()->getAddWordsDialogSize());
    connectSignals();

    addRadioButton->setChecked(true);
    onAddReadRadioBtnClicked();

    previewView->setContextMenuPolicy(Qt::CustomContextMenu);

    QStandardItemModel* model = Document::getInstance()->getModel(true);
    previewView->setModel(model);
    previewView->header()->setResizeMode(QHeaderView::ResizeToContents);

    for (int i = 0; i < model->rowCount(); ++i) {
        setComboBox->addItem(model->index(i, 0).data(Qt::EditRole).toString());
    }
    autosavingCheckBox->setChecked(Document::getInstance()->getIsAutosavingEnabled());

    createActions();
}

AddNewWordsDialog::~AddNewWordsDialog()
{
}

// init functions

void AddNewWordsDialog::connectSignals()
{
    connect(addRadioButton, SIGNAL(clicked()), this, SLOT(onAddReadRadioBtnClicked()));
    connect(readRadioButton, SIGNAL(clicked()), this, SLOT(onAddReadRadioBtnClicked()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(onBrowseBtnClicked()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(onAddBtnClicked()));
    connect(addSetBtn, SIGNAL(clicked()), this, SLOT(onAddSetBtnClicked()));
    connect(saveBtn, SIGNAL(clicked()), this, SLOT(onSaveBtnClicked()));
    connect(autosavingCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onAutosavingCheckBoxStateChanged(int)));

    connect(previewView, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void AddNewWordsDialog::createActions()
{
    m_pDeleteSetAction = new QAction(tr("Delete Set"), this);
    connect(m_pDeleteSetAction, SIGNAL(triggered()), this, SLOT(onDeleteSet()));

    m_pDeleteWordAction = new QAction(tr("Delete Word"), this);
    connect(m_pDeleteWordAction, SIGNAL(triggered()), this, SLOT(onDeleteWord()));
}

// protected slots

void AddNewWordsDialog::onAddReadRadioBtnClicked()
{
    bool isReadFileMode = readRadioButton->isChecked();
    originalLineEdit->setEnabled(!isReadFileMode);
    translatedLineEdit->setEnabled(!isReadFileMode);
    filePathLineEdit->setEnabled(isReadFileMode);
    browseButton->setEnabled(isReadFileMode);
}

void AddNewWordsDialog::onAddBtnClicked()
{
    bool isReadFileMode = readRadioButton->isChecked();
    if (isReadFileMode) {
        readWordsToPreview();
    } else {
        addWordsToPreview();
    }
    if (Document::getInstance()->getIsAutosavingEnabled()) {
        onSaveBtnClicked();
    }
}

void AddNewWordsDialog::onBrowseBtnClicked()
{
    m_wordsFilePath = QFileDialog::getOpenFileName(this,
     tr("Open file with new words"), "./", tr("Any Files (*)"));
    filePathLineEdit->setText(m_wordsFilePath);
}

void AddNewWordsDialog::onAddSetBtnClicked()
{
    QStandardItemModel* model = Document::getInstance()->getModel();
    // try to find set in model
    if (model->findItems(setComboBox->currentText()).isEmpty()) {
        // if not exists - add it
        QStandardItem *item = new QStandardItem(setComboBox->currentText());
        int rowsCount = model->rowCount();
        model->setItem(rowsCount, 0, item);
        // add new set to combo items
        setComboBox->addItem(setComboBox->currentText());
        // save set to data base if autosaving enabled
        if (Document::getInstance()->getIsAutosavingEnabled()) {
            onSaveBtnClicked();
        }
    } else {
        QMessageBox::warning(this, tr("Add set"),
            tr("Set is already exist.\n"),
            QMessageBox::Ok,
            QMessageBox::Ok);
    }
}

void AddNewWordsDialog::onSaveBtnClicked()
{
    Document::getInstance()->saveModelToXml();
}

void AddNewWordsDialog::showContextMenu(const QPoint &position)
{
    QList<QAction *> actions;
    if (previewView->indexAt(position).isValid()) {
        if (previewView->indexAt(position).parent().isValid()) {
            actions.append(m_pDeleteWordAction);
        } else {
            actions.append(m_pDeleteSetAction);
        }
    }
    if (actions.count() > 0) {
        QMenu::exec(actions, previewView->mapToGlobal(position));
    }
}

void AddNewWordsDialog::onDeleteSet()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("Delete Set"),
       QString(tr("Are you sure you want to " \
       "delete set '%1' and all its contents?"))
       .arg(previewView->currentIndex().data(Qt::EditRole).toString()),
       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        previewView->model()->removeRow(previewView->currentIndex().row());
    }
}

void AddNewWordsDialog::onDeleteWord()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("Delete Word"),
       QString(tr("Are you sure you want to " \
       "delete this word?")),
       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
         previewView->model()->removeRow(previewView->currentIndex().row(), previewView->currentIndex().parent());
    }
}

void AddNewWordsDialog::onAutosavingCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        onSaveBtnClicked();
    }
    saveBtn->setEnabled(!autosavingCheckBox->isChecked());
    Document::getInstance()->getIsAutosavingEnabled() = autosavingCheckBox->isChecked();
}

// protected functions

void AddNewWordsDialog::resizeEvent(QResizeEvent * event)
{
    Document::getInstance()->getAddWordsDialogSize() = this->size();
    QDialog::resizeEvent(event);
}

void AddNewWordsDialog::addWordsToPreview()
{
    if (setComboBox->currentText().isEmpty()
        || originalLineEdit->text().isEmpty() || translatedLineEdit->text().isEmpty()
        || languageOriginalComboBox->currentText().isEmpty() || languageTranslatedComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Add files"),
            tr("Not all required data set.\n"),
            QMessageBox::Ok,
            QMessageBox::Ok);
    } else {
        QStandardItem* newItem = Document::getInstance()->addNewWordsToModel(setComboBox->currentText()
                            , originalLineEdit->text() , translatedLineEdit->text()
                            , languageOriginalComboBox->currentText(), languageTranslatedComboBox->currentText());
        previewView->setCurrentIndex(newItem->index());
    }
}

void AddNewWordsDialog::readWordsToPreview()
{
    if (setComboBox->currentText().isEmpty() || filePathLineEdit->text().isEmpty()
        || languageOriginalComboBox->currentText().isEmpty() || languageTranslatedComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Add files"),
            tr("Not all required data set.\n"),
            QMessageBox::Ok,
            QMessageBox::Ok);
    } else {
        QFile file(m_wordsFilePath);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);

        QString line;

        while (in.atEnd() == false) {
            line = in.readLine();
            QString separator(":");
            QStringList strList = line.split(separator);
            if (strList.size() < 2) {
                QMessageBox::critical(this, tr("Add files"),
                tr("Not all required data set.\n"),
                QMessageBox::Ok,
                QMessageBox::Ok);
                return;
            }
            Document::getInstance()->addNewWordsToModel(setComboBox->currentText()
                            , strList[0] , strList[1]
                            , languageOriginalComboBox->currentText(), languageTranslatedComboBox->currentText());
        }
        file.close();
    }
}

void AddNewWordsDialog::reject()
{
    if (Document::getInstance()->getIsAutosavingEnabled()) {
        onSaveBtnClicked();
    }
    QDialog::reject();
}
