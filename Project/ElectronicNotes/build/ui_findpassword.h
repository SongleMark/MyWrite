/********************************************************************************
** Form generated from reading UI file 'findpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORD_H
#define UI_FINDPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindPassword
{
public:
    QPushButton *pushButton_modify;
    QPushButton *pushButton_sure;
    QLabel *label_return;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_tel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_emil;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_passwordsure;

    void setupUi(QWidget *FindPassword)
    {
        if (FindPassword->objectName().isEmpty())
            FindPassword->setObjectName(QStringLiteral("FindPassword"));
        FindPassword->resize(480, 405);
        FindPassword->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        pushButton_modify = new QPushButton(FindPassword);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        pushButton_modify->setGeometry(QRect(180, 320, 89, 25));
        pushButton_modify->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        pushButton_sure = new QPushButton(FindPassword);
        pushButton_sure->setObjectName(QStringLiteral("pushButton_sure"));
        pushButton_sure->setGeometry(QRect(330, 170, 89, 25));
        pushButton_sure->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        label_return = new QLabel(FindPassword);
        label_return->setObjectName(QStringLiteral("label_return"));
        label_return->setGeometry(QRect(60, 170, 251, 21));
        label_return->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));
        widget = new QWidget(FindPassword);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 40, 361, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(label);

        lineEdit_tel = new QLineEdit(widget);
        lineEdit_tel->setObjectName(QStringLiteral("lineEdit_tel"));
        lineEdit_tel->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(lineEdit_tel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_emil = new QLineEdit(widget);
        lineEdit_emil->setObjectName(QStringLiteral("lineEdit_emil"));
        lineEdit_emil->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(lineEdit_emil);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(FindPassword);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(60, 200, 361, 101));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_password = new QLineEdit(widget1);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(lineEdit_password);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_passwordsure = new QLineEdit(widget1);
        lineEdit_passwordsure->setObjectName(QStringLiteral("lineEdit_passwordsure"));
        lineEdit_passwordsure->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(lineEdit_passwordsure);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(FindPassword);

        QMetaObject::connectSlotsByName(FindPassword);
    } // setupUi

    void retranslateUi(QWidget *FindPassword)
    {
        FindPassword->setWindowTitle(QApplication::translate("FindPassword", "Form", Q_NULLPTR));
        pushButton_modify->setText(QApplication::translate("FindPassword", "\346\233\264\346\224\271", Q_NULLPTR));
        pushButton_sure->setText(QApplication::translate("FindPassword", "\350\276\223\345\205\245\347\241\256\350\256\244", Q_NULLPTR));
        label_return->setText(QString());
        label->setText(QApplication::translate("FindPassword", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\347\240\201:", Q_NULLPTR));
        label_2->setText(QApplication::translate("FindPassword", "\350\257\267\350\276\223\345\205\245emil\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("FindPassword", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201:", Q_NULLPTR));
        label_4->setText(QApplication::translate("FindPassword", "\350\257\267\347\241\256\350\256\244\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindPassword: public Ui_FindPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORD_H
