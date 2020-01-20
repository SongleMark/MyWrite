/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Query
{
public:
    QPushButton *pushButton_pre;
    QPushButton *pushButton_next;
    QPushButton *pushButton_add;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_display;
    QTextEdit *textEdit_show;
    QComboBox *comboBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_query;
    QPushButton *pushButton_query;
    QTableWidget *tableWidget;
    QPushButton *pushButton_update;

    void setupUi(QWidget *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(1262, 716);
        Query->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        pushButton_pre = new QPushButton(Query);
        pushButton_pre->setObjectName(QStringLiteral("pushButton_pre"));
        pushButton_pre->setGeometry(QRect(410, 670, 89, 25));
        pushButton_pre->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        pushButton_next = new QPushButton(Query);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setGeometry(QRect(1150, 670, 89, 25));
        pushButton_next->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        pushButton_add = new QPushButton(Query);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(790, 670, 89, 25));
        pushButton_add->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        layoutWidget = new QWidget(Query);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(410, 10, 831, 651));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_display = new QLabel(layoutWidget);
        label_display->setObjectName(QStringLiteral("label_display"));
        label_display->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(label_display);

        textEdit_show = new QTextEdit(layoutWidget);
        textEdit_show->setObjectName(QStringLiteral("textEdit_show"));
        textEdit_show->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(textEdit_show);

        comboBox = new QComboBox(Query);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 311, 41));
        comboBox->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        layoutWidget1 = new QWidget(Query);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 60, 391, 641));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_query = new QLineEdit(layoutWidget1);
        lineEdit_query->setObjectName(QStringLiteral("lineEdit_query"));
        lineEdit_query->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(lineEdit_query);

        pushButton_query = new QPushButton(layoutWidget1);
        pushButton_query->setObjectName(QStringLiteral("pushButton_query"));
        pushButton_query->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(pushButton_query);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(layoutWidget1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout->addWidget(tableWidget);

        pushButton_update = new QPushButton(Query);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        pushButton_update->setGeometry(QRect(328, 10, 71, 41));
        pushButton_update->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        retranslateUi(Query);

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QWidget *Query)
    {
        Query->setWindowTitle(QApplication::translate("Query", "Form", Q_NULLPTR));
        pushButton_pre->setText(QApplication::translate("Query", "\344\270\212\344\270\200\346\235\241", Q_NULLPTR));
        pushButton_next->setText(QApplication::translate("Query", "\344\270\213\344\270\200\346\235\241", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("Query", "\346\267\273\345\212\240\346\226\260\347\254\224\350\256\260", Q_NULLPTR));
        label_display->setText(QApplication::translate("Query", "<html><head/><body><p align=\"center\">\347\254\224\350\256\260\345\206\205\345\256\271(\350\257\267\347\202\271\345\207\273\345\267\246\344\276\247\347\233\270\345\272\224\347\254\224\350\256\260\346\240\207\351\242\230)</p></body></html>", Q_NULLPTR));
        pushButton_query->setText(QApplication::translate("Query", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_update->setText(QApplication::translate("Query", "\346\233\264\346\226\260/\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
