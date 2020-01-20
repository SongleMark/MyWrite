/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_Mainwindow
{
public:
    QLabel *label;
    QPushButton *register_2;
    QPushButton *login;
    QLabel *forgetp;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *user;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *password;

    void setupUi(QWidget *Mainwindow)
    {
        if (Mainwindow->objectName().isEmpty())
            Mainwindow->setObjectName(QStringLiteral("Mainwindow"));
        Mainwindow->resize(484, 421);
        Mainwindow->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label = new QLabel(Mainwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 20, 301, 41));
        label->setStyleSheet(QLatin1String("color: rgb(138, 226, 52);\n"
"font: 75 16pt \"Ubuntu Condensed\";"));
        register_2 = new QPushButton(Mainwindow);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(90, 280, 89, 25));
        register_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        login = new QPushButton(Mainwindow);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(310, 280, 89, 25));
        login->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        forgetp = new QLabel(Mainwindow);
        forgetp->setObjectName(QStringLiteral("forgetp"));
        forgetp->setGeometry(QRect(330, 370, 71, 21));
        forgetp->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));
        layoutWidget = new QWidget(Mainwindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 100, 311, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 23));
        label_2->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(label_2);

        user = new QLineEdit(layoutWidget);
        user->setObjectName(QStringLiteral("user"));
        user->setMinimumSize(QSize(171, 31));
        user->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout_2->addWidget(user);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(60, 23));
        label_3->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(label_3);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setMinimumSize(QSize(171, 31));
        password->setStyleSheet(QStringLiteral("color: rgb(138, 226, 52);"));

        horizontalLayout->addWidget(password);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Mainwindow);

        QMetaObject::connectSlotsByName(Mainwindow);
    } // setupUi

    void retranslateUi(QWidget *Mainwindow)
    {
        Mainwindow->setWindowTitle(QApplication::translate("Mainwindow", "Mainwindow", Q_NULLPTR));
        label->setText(QApplication::translate("Mainwindow", "<html><head/><body><p align=\"center\">SongleMark---Notes</p></body></html>", Q_NULLPTR));
        register_2->setText(QApplication::translate("Mainwindow", "\346\263\250\345\206\214", Q_NULLPTR));
        login->setText(QApplication::translate("Mainwindow", "\347\231\273\345\275\225", Q_NULLPTR));
        forgetp->setText(QString());
        label_2->setText(QApplication::translate("Mainwindow", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Mainwindow", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
