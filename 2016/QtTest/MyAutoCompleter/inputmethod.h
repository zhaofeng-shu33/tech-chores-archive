#ifndef INPUTMETHOD_H
#define INPUTMETHOD_H

#include <QDialog>

class QLineEdit;
class TextSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextSearchDialog(QDialog *parent = 0);
    ~TextSearchDialog();
private:
    QLineEdit* lineEdit;
    QPushButton* nextButton;
    QPushButton* cancelButton;
};

#endif // INPUTMETHOD_H
