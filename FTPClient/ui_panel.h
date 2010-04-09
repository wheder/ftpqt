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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetFTP;
    QTreeWidget *treeWidgetLocal;
    QLabel *label_2;
    QPushButton *cdUpFTP;
    QLabel *label;
    QPushButton *uploadButton;
    QPushButton *renameButton;
    QPushButton *deleteButton;
    QPushButton *downloadButton;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(928, 394);
        gridLayout = new QGridLayout(Panel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetFTP = new QTreeWidget(Panel);
        treeWidgetFTP->setObjectName(QString::fromUtf8("treeWidgetFTP"));
        treeWidgetFTP->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetFTP, 3, 3, 1, 2);

        treeWidgetLocal = new QTreeWidget(Panel);
        treeWidgetLocal->setObjectName(QString::fromUtf8("treeWidgetLocal"));
        treeWidgetLocal->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetLocal, 3, 0, 1, 2);

        label_2 = new QLabel(Panel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        cdUpFTP = new QPushButton(Panel);
        cdUpFTP->setObjectName(QString::fromUtf8("cdUpFTP"));

        gridLayout->addWidget(cdUpFTP, 0, 4, 1, 1);

        label = new QLabel(Panel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        uploadButton = new QPushButton(Panel);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));

        gridLayout->addWidget(uploadButton, 4, 0, 1, 1);

        renameButton = new QPushButton(Panel);
        renameButton->setObjectName(QString::fromUtf8("renameButton"));

        gridLayout->addWidget(renameButton, 4, 1, 1, 1);

        deleteButton = new QPushButton(Panel);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 4, 3, 1, 1);

        downloadButton = new QPushButton(Panel);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));

        gridLayout->addWidget(downloadButton, 4, 4, 1, 1);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QApplication::translate("Panel", "Form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetFTP->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("Panel", "Time", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("Panel", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Panel", "Name", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetLocal->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("Panel", "Time", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Panel", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Panel", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Panel", "FTP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        cdUpFTP->setWhatsThis(QApplication::translate("Panel", "blbeeeeeeeeeeeeeeeeeeeec\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cdUpFTP->setText(QApplication::translate("Panel", "\342\206\221 (Up) (..)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Panel", "Local", 0, QApplication::UnicodeUTF8));
        uploadButton->setText(QApplication::translate("Panel", "Upload", 0, QApplication::UnicodeUTF8));
        renameButton->setText(QApplication::translate("Panel", "Rename", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("Panel", "Delete", 0, QApplication::UnicodeUTF8));
        downloadButton->setText(QApplication::translate("Panel", "Download", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
