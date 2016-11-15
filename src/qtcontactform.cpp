#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QFormLayout>
#include "qtcontactform.h"
#include <QDoubleValidator>


QtContactForm::QtContactForm(QWidget *parent) : 
        QFormLayout(parent), firstNameField(new QLineEdit()),
        lastNameField(new QLineEdit()),
        addressField(new QTextEdit()),
        phoneField(new QComboBox()),
        phoneNumberField(new QLineEdit()),
         emailField(new QLineEdit())



{
    addRow("First Name", firstNameField);
    addRow("Last Name", lastNameField);
    addRow("Address", addressField);
    addRow("Phone",  phoneField);
    phoneField->addItem(tr("Home"));
    phoneField->addItem(tr("work"));
    phoneField->addItem(tr("Other"));
    addRow("Phone Number", phoneNumberField);
    QRegExp rx( "-?\\d{0,10}" ); /* allowed to type (10 digits) */
    QValidator* validatorNum = new QRegExpValidator( rx, this );
    phoneNumberField->setValidator(validatorNum);
    addRow("Email", emailField);
    /*QRegExp regmat( "[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}" );
    QValidator* validatormail = new QRegExpValidator( regmat, this );
    emailField->setValidator(validatormail);
    if (regmat.exactMatch(emailField))
            return true;

   return false;*/

}

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setHtml("");
    phoneField->setCurrentText("");
    phoneNumberField->setText("");
    emailField->setText("");
}
