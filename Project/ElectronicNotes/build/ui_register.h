/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *register_2;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *password_sure;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *sex;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *tel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *emil;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(400, 489);
        Register->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        register_2 = new QPushButton(Register);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(150, 430, 89, 25));
        register_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 20, 81, 31));
        label_6->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 70, 291, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(label);

        name = new QLineEdit(layoutWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(171, 31));
        name->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setMinimumSize(QSize(171, 31));
        password->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_6->addWidget(label_7);

        password_sure = new QLineEdit(layoutWidget);
        password_sure->setObjectName(QStringLiteral("password_sure"));
        password_sure->setMinimumSize(QSize(171, 31));
        password_sure->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_6->addWidget(password_sure);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(label_3);

        sex = new QComboBox(layoutWidget);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_3->addWidget(sex);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(label_4);

        tel = new QLineEdit(layoutWidget);
        tel->setObjectName(QStringLiteral("tel"));
        tel->setMinimumSize(QSize(171, 31));
        tel->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(tel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_5->addWidget(label_5);

        emil = new QLineEdit(layoutWidget);
        emil->setObjectName(QStringLiteral("emil"));
        emil->setMinimumSize(QSize(171, 31));
        emil->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_5->addWidget(emil);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", Q_NULLPTR));
        register_2->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\350\257\267\350\276\223\345\205\245\344\277\241\346\201\257</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\346\230\265\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("Register", "\347\241\256\350\256\244", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\346\200\247\345\210\253", Q_NULLPTR));
        sex->clear();
        sex->insertItems(0, QStringList()
         << QApplication::translate("Register", "\347\224\267", Q_NULLPTR)
         << QApplication::translate("Register", "\345\245\263", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Register", "\347\224\265\350\257\235", Q_NULLPTR));
        label_5->setText(QApplication::translate("Register", "Emil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
