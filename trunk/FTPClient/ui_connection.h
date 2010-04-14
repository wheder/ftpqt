/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *serverAddress;
    QCheckBox *anonymousConnection;
    QLabel *label_2;
    QLineEdit *user;
    QLabel *label_3;
    QLineEdit *password;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;
    QLabel *statusLabel;
    QSpinBox *maxConnections;

    void setupUi(QDialog *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->resize(330, 215);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/dir.png"), QSize(), QIcon::Normal, QIcon::Off);
        Connection->setWindowIcon(icon);
        formLayout = new QFormLayout(Connection);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(Connection);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        serverAddress = new QLineEdit(Connection);
        serverAddress->setObjectName(QString::fromUtf8("serverAddress"));

        formLayout->setWidget(0, QFormLayout::FieldRole, serverAddress);

        anonymousConnection = new QCheckBox(Connection);
        anonymousConnection->setObjectName(QString::fromUtf8("anonymousConnection"));
        anonymousConnection->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, anonymousConnection);

        label_2 = new QLabel(Connection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        user = new QLineEdit(Connection);
        user->setObjectName(QString::fromUtf8("user"));
        user->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, user);

        label_3 = new QLabel(Connection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        password = new QLineEdit(Connection);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEnabled(false);
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, password);

        label_4 = new QLabel(Connection);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_4);

        buttonBox = new QDialogButtonBox(Connection);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        formLayout->setWidget(9, QFormLayout::SpanningRole, buttonBox);

        statusLabel = new QLabel(Connection);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        formLayout->setWidget(10, QFormLayout::SpanningRole, statusLabel);

        maxConnections = new QSpinBox(Connection);
        maxConnections->setObjectName(QString::fromUtf8("maxConnections"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maxConnections->sizePolicy().hasHeightForWidth());
        maxConnections->setSizePolicy(sizePolicy);
        maxConnections->setWrapping(false);
        maxConnections->setMinimum(1);

        formLayout->setWidget(7, QFormLayout::FieldRole, maxConnections);


        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QDialog *Connection)
    {
        Connection->setWindowTitle(QApplication::translate("Connection", "Connection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Connection", "Server:", 0, QApplication::UnicodeUTF8));
        anonymousConnection->setText(QApplication::translate("Connection", "Anonymous", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Connection", "User:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Connection", "Password:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Connection", "Maximum connections:", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
