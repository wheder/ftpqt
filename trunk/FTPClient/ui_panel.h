/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *cdUpFTP;
    QTreeWidget *treeWidgetLocal;
    QTreeWidget *treeWidgetFTP;
    QPushButton *uploadButton;
    QPushButton *renameButton;
    QPushButton *deleteButton;
    QPushButton *downloadButton;
    QScrollArea *transferScrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *label_3;
    QProgressBar *progressBar;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(928, 512);
        gridLayout = new QGridLayout(Panel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Panel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Panel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        cdUpFTP = new QPushButton(Panel);
        cdUpFTP->setObjectName(QString::fromUtf8("cdUpFTP"));

        gridLayout->addWidget(cdUpFTP, 0, 3, 1, 1);

        treeWidgetLocal = new QTreeWidget(Panel);
        treeWidgetLocal->setObjectName(QString::fromUtf8("treeWidgetLocal"));
        treeWidgetLocal->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetLocal, 1, 0, 1, 2);

        treeWidgetFTP = new QTreeWidget(Panel);
        treeWidgetFTP->setObjectName(QString::fromUtf8("treeWidgetFTP"));
        treeWidgetFTP->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetFTP, 1, 2, 1, 2);

        uploadButton = new QPushButton(Panel);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));

        gridLayout->addWidget(uploadButton, 3, 0, 1, 1);

        renameButton = new QPushButton(Panel);
        renameButton->setObjectName(QString::fromUtf8("renameButton"));

        gridLayout->addWidget(renameButton, 3, 1, 1, 1);

        deleteButton = new QPushButton(Panel);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 3, 2, 1, 1);

        downloadButton = new QPushButton(Panel);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));

        gridLayout->addWidget(downloadButton, 3, 3, 1, 1);

        transferScrollArea = new QScrollArea(Panel);
        transferScrollArea->setObjectName(QString::fromUtf8("transferScrollArea"));
        transferScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 914, 216));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        formLayout->setWidget(0, QFormLayout::FieldRole, progressBar);

        transferScrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(transferScrollArea, 4, 0, 1, 4);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        label->setText(QApplication::translate("Panel", "Local", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Panel", "FTP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        cdUpFTP->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        cdUpFTP->setText(QApplication::translate("Panel", "\342\206\221 (Up) (..)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetLocal->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("Panel", "Time", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("Panel", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Panel", "Name", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetFTP->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("Panel", "Time", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Panel", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Panel", "Name", 0, QApplication::UnicodeUTF8));
        uploadButton->setText(QApplication::translate("Panel", "Upload", 0, QApplication::UnicodeUTF8));
        renameButton->setText(QApplication::translate("Panel", "Rename", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("Panel", "Delete", 0, QApplication::UnicodeUTF8));
        downloadButton->setText(QApplication::translate("Panel", "Download", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Panel", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Panel);
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
