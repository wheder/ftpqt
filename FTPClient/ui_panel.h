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
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetFTP;
    QTreeWidget *treeWidgetLocal;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(928, 579);
        gridLayout = new QGridLayout(Panel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetFTP = new QTreeWidget(Panel);
        treeWidgetFTP->setObjectName(QString::fromUtf8("treeWidgetFTP"));
        treeWidgetFTP->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetFTP, 1, 3, 1, 1);

        treeWidgetLocal = new QTreeWidget(Panel);
        treeWidgetLocal->setObjectName(QString::fromUtf8("treeWidgetLocal"));
        treeWidgetLocal->setRootIsDecorated(false);

        gridLayout->addWidget(treeWidgetLocal, 1, 2, 1, 1);

        label = new QLabel(Panel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        label_2 = new QLabel(Panel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);


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
        label->setText(QApplication::translate("Panel", "Local", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Panel", "FTP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
