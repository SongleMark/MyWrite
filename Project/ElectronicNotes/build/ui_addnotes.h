/********************************************************************************
** Form generated from reading UI file 'addnotes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTES_H
#define UI_ADDNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNotes
{
public:
    QPushButton *addnote;
    QPushButton *clear;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *createbook;
    QLineEdit *notebook;
    QPushButton *originabook;
    QComboBox *book;
    QLabel *label_2;
    QLineEdit *title;
    QLabel *label_4;
    QTextEdit *contents;
    QLabel *label_display_2;

    void setupUi(QWidget *AddNotes)
    {
        if (AddNotes->objectName().isEmpty())
            AddNotes->setObjectName(QStringLiteral("AddNotes"));
        AddNotes->resize(829, 692);
        AddNotes->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        addnote = new QPushButton(AddNotes);
        addnote->setObjectName(QStringLiteral("addnote"));
        addnote->setGeometry(QRect(710, 650, 89, 25));
        addnote->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        clear = new QPushButton(AddNotes);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(40, 650, 89, 25));
        clear->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        layoutWidget = new QWidget(AddNotes);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 2, 801, 641));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        createbook = new QPushButton(layoutWidget);
        createbook->setObjectName(QStringLiteral("createbook"));
        createbook->setMinimumSize(QSize(83, 31));
        createbook->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(createbook, 1, 0, 1, 2);

        notebook = new QLineEdit(layoutWidget);
        notebook->setObjectName(QStringLiteral("notebook"));
        notebook->setStyleSheet(QLatin1String("color: rgb(138, 226, 52);\n"
"color: rgb(138, 226, 52);\n"
"background-color: rgb(136, 138, 133);"));

        gridLayout->addWidget(notebook, 1, 2, 1, 1);

        originabook = new QPushButton(layoutWidget);
        originabook->setObjectName(QStringLiteral("originabook"));
        originabook->setMinimumSize(QSize(83, 31));
        originabook->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(originabook, 2, 0, 1, 2);

        book = new QComboBox(layoutWidget);
        book->setObjectName(QStringLiteral("book"));
        book->setStyleSheet(QLatin1String("color: rgb(138, 226, 52);\n"
"background-color: rgb(136, 138, 133);"));

        gridLayout->addWidget(book, 2, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        title = new QLineEdit(layoutWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(title, 3, 1, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        contents = new QTextEdit(layoutWidget);
        contents->setObjectName(QStringLiteral("contents"));
        contents->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(contents, 4, 1, 1, 2);

        label_display_2 = new QLabel(layoutWidget);
        label_display_2->setObjectName(QStringLiteral("label_display_2"));
        label_display_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        gridLayout->addWidget(label_display_2, 0, 0, 1, 3);


        retranslateUi(AddNotes);

        QMetaObject::connectSlotsByName(AddNotes);
    } // setupUi

    void retranslateUi(QWidget *AddNotes)
    {
        AddNotes->setWindowTitle(QApplication::translate("AddNotes", "Form", Q_NULLPTR));
        addnote->setText(QApplication::translate("AddNotes", "\346\267\273\345\212\240", Q_NULLPTR));
        clear->setText(QApplication::translate("AddNotes", "\346\270\205\351\231\244\345\206\205\345\256\271", Q_NULLPTR));
        createbook->setText(QApplication::translate("AddNotes", "\346\226\260\345\273\272\347\254\224\350\256\260\346\234\254", Q_NULLPTR));
        originabook->setText(QApplication::translate("AddNotes", "\345\216\237\346\234\211\347\254\224\350\256\260\346\234\254", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddNotes", "\346\240\207\351\242\230", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddNotes", "\345\206\205\345\256\271", Q_NULLPTR));
        label_display_2->setText(QApplication::translate("AddNotes", "<html><head/><body><p align=\"center\">\346\267\273\345\212\240\347\254\224\350\256\260(\350\257\267\345\205\210\347\202\271\345\207\273\346\226\260\345\273\272\347\254\224\350\256\260\346\210\226\345\216\237\346\234\211\347\254\224\350\256\260\346\234\254)</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNotes: public Ui_AddNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTES_H
