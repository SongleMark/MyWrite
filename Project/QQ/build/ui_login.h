/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_6;
    QLabel *label_pic;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *label_phone;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_birthday;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_user;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label_ID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QLabel *label_time;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(597, 829);
        Login->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label_6 = new QLabel(Login);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 40, 101, 21));
        label_6->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        label_pic = new QLabel(Login);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(26, 70, 291, 241));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 330, 561, 471));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_7->addWidget(label);

        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_7->addWidget(label_name);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_6->addWidget(label_2);

        label_phone = new QLabel(layoutWidget);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_6->addWidget(label_phone);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_5->addWidget(label_3);

        label_birthday = new QLabel(layoutWidget);
        label_birthday->setObjectName(QStringLiteral("label_birthday"));
        label_birthday->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_5->addWidget(label_birthday);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(label_4);

        label_user = new QLabel(layoutWidget);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(label_user);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(label_5);

        label_ID = new QLabel(layoutWidget);
        label_ID->setObjectName(QStringLiteral("label_ID"));
        label_ID->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(label_ID);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(label_14);

        label_time = new QLabel(layoutWidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(label_time);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(Login);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 30, 241, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(pushButton_4);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", Q_NULLPTR));
        label_6->setText(QApplication::translate("Login", "<html><head/><body><p>\345\244\264\345\203\217</p></body></html>", Q_NULLPTR));
        label_pic->setText(QString());
        label->setText(QApplication::translate("Login", "\346\230\265\347\247\260\357\274\232", Q_NULLPTR));
        label_name->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\347\224\265\350\257\235\357\274\232", Q_NULLPTR));
        label_phone->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\347\224\237\346\227\245\357\274\232", Q_NULLPTR));
        label_birthday->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Login", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        label_user->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Login", "IDCARD\357\274\232", Q_NULLPTR));
        label_ID->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("Login", "\346\263\250\345\206\214\346\227\266\351\227\264", Q_NULLPTR));
        label_time->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\">------------</p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Login", "\344\277\256\346\224\271\350\207\252\350\272\253\344\277\241\346\201\257", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Login", "\344\270\216\344\273\226\344\272\272\351\200\232\344\277\241", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Login", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Login", "\345\245\275\345\217\213\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
