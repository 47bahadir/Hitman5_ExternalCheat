/********************************************************************************
** Form generated from reading UI file 'Hitman5_External.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HITMAN5_EXTERNAL_H
#define UI_HITMAN5_EXTERNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hitman5_ExternalClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *Change_Value;
    QHBoxLayout *horizontalLayout;
    QLabel *Health_label;
    QLineEdit *Health_EditLine;
    QPushButton *Health_ApplyButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *R_PistolAmmo_label;
    QLineEdit *R_PistolAmmo_EditLine;
    QPushButton *R_PistolAmmo_ApplyButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *L_PistolAmmo_label;
    QLineEdit *L_PistolAmmo_EditLine;
    QPushButton *L_PistolAmmo_ApplyButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *X_Posation_label;
    QLineEdit *X_Posation_EditLine;
    QPushButton *X_Posation_ApplyButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Y_Posation_label;
    QLineEdit *Y_Posation_EditLine;
    QPushButton *Y_Posation_ApplyButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Z_Posation_label;
    QLineEdit *Z_Posation_EditLine;
    QPushButton *Z_Posation_ApplyButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *LockHealth_checkBox;
    QCheckBox *LockAmmo_checkBox;

    void setupUi(QMainWindow *Hitman5_ExternalClass)
    {
        if (Hitman5_ExternalClass->objectName().isEmpty())
            Hitman5_ExternalClass->setObjectName(QString::fromUtf8("Hitman5_ExternalClass"));
        Hitman5_ExternalClass->resize(590, 599);
        Hitman5_ExternalClass->setMinimumSize(QSize(590, 599));
        Hitman5_ExternalClass->setStyleSheet(QString::fromUtf8("\n"
"        QMainWindow {\n"
"        background-color: #1e1e1e;\n"
"        }\n"
"        QWidget {\n"
"        background-color: #1e1e1e;\n"
"        color: #ffffff;\n"
"        }\n"
"        QLabel {\n"
"        color: #ffffff;\n"
"        }\n"
"        QLineEdit {\n"
"        background-color: #2d2d2d;\n"
"        color: #ffffff;\n"
"        border: 1px solid #3d3d3d;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        }\n"
"        QPushButton {\n"
"        background-color: #3d3d3d;\n"
"        color: #ffffff;\n"
"        border: none;\n"
"        border-radius: 3px;\n"
"        padding: 5px;\n"
"        }\n"
"        QPushButton:hover {\n"
"        background-color: #4d4d4d;\n"
"        }\n"
"        QPushButton:pressed {\n"
"        background-color: #2d2d2d;\n"
"        }\n"
"        QCheckBox {\n"
"        color: #ffffff;\n"
"        }\n"
"        QCheckBox::indicator {\n"
"        width: 13px;\n"
"        height: 13px;\n"
"        border: 1px solid #3d3d3d;\n"
"        border-radi"
                        "us: 2px;\n"
"        }\n"
"        QCheckBox::indicator:unchecked {\n"
"        background-color: #2d2d2d;\n"
"        }\n"
"        QCheckBox::indicator:checked {\n"
"        background-color: #4d4d4d;\n"
"        }\n"
"        QMessageBox {\n"
"        background-color: #1e1e1e;\n"
"        color: #ffffff;\n"
"        }\n"
"        QMessageBox QLabel {\n"
"        color: #ffffff;\n"
"        }\n"
"        QMessageBox QPushButton {\n"
"        background-color: #3d3d3d;\n"
"        color: #ffffff;\n"
"        border: none;\n"
"        border-radius: 3px;\n"
"        padding: 5px 10px;\n"
"        min-width: 60px;\n"
"        }\n"
"        QMessageBox QPushButton:hover {\n"
"        background-color: #4d4d4d;\n"
"        }\n"
"        QMessageBox QPushButton:pressed {\n"
"        background-color: #2d2d2d;\n"
"        }\n"
"      "));
        centralWidget = new QWidget(Hitman5_ExternalClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Change_Value = new QVBoxLayout();
        Change_Value->setSpacing(30);
        Change_Value->setObjectName(QString::fromUtf8("Change_Value"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Health_label = new QLabel(centralWidget);
        Health_label->setObjectName(QString::fromUtf8("Health_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bell MT"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        Health_label->setFont(font);

        horizontalLayout->addWidget(Health_label);

        Health_EditLine = new QLineEdit(centralWidget);
        Health_EditLine->setObjectName(QString::fromUtf8("Health_EditLine"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Health_EditLine->sizePolicy().hasHeightForWidth());
        Health_EditLine->setSizePolicy(sizePolicy);
        Health_EditLine->setMaximumSize(QSize(100, 20));

        horizontalLayout->addWidget(Health_EditLine);

        Health_ApplyButton = new QPushButton(centralWidget);
        Health_ApplyButton->setObjectName(QString::fromUtf8("Health_ApplyButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Health_ApplyButton->sizePolicy().hasHeightForWidth());
        Health_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Health_ApplyButton);


        Change_Value->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        R_PistolAmmo_label = new QLabel(centralWidget);
        R_PistolAmmo_label->setObjectName(QString::fromUtf8("R_PistolAmmo_label"));
        R_PistolAmmo_label->setFont(font);

        horizontalLayout_2->addWidget(R_PistolAmmo_label);

        R_PistolAmmo_EditLine = new QLineEdit(centralWidget);
        R_PistolAmmo_EditLine->setObjectName(QString::fromUtf8("R_PistolAmmo_EditLine"));
        sizePolicy.setHeightForWidth(R_PistolAmmo_EditLine->sizePolicy().hasHeightForWidth());
        R_PistolAmmo_EditLine->setSizePolicy(sizePolicy);
        R_PistolAmmo_EditLine->setMaximumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(R_PistolAmmo_EditLine);

        R_PistolAmmo_ApplyButton = new QPushButton(centralWidget);
        R_PistolAmmo_ApplyButton->setObjectName(QString::fromUtf8("R_PistolAmmo_ApplyButton"));
        sizePolicy1.setHeightForWidth(R_PistolAmmo_ApplyButton->sizePolicy().hasHeightForWidth());
        R_PistolAmmo_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(R_PistolAmmo_ApplyButton);


        Change_Value->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        L_PistolAmmo_label = new QLabel(centralWidget);
        L_PistolAmmo_label->setObjectName(QString::fromUtf8("L_PistolAmmo_label"));
        L_PistolAmmo_label->setFont(font);

        horizontalLayout_6->addWidget(L_PistolAmmo_label);

        L_PistolAmmo_EditLine = new QLineEdit(centralWidget);
        L_PistolAmmo_EditLine->setObjectName(QString::fromUtf8("L_PistolAmmo_EditLine"));
        sizePolicy.setHeightForWidth(L_PistolAmmo_EditLine->sizePolicy().hasHeightForWidth());
        L_PistolAmmo_EditLine->setSizePolicy(sizePolicy);
        L_PistolAmmo_EditLine->setMaximumSize(QSize(100, 20));

        horizontalLayout_6->addWidget(L_PistolAmmo_EditLine);

        L_PistolAmmo_ApplyButton = new QPushButton(centralWidget);
        L_PistolAmmo_ApplyButton->setObjectName(QString::fromUtf8("L_PistolAmmo_ApplyButton"));
        sizePolicy1.setHeightForWidth(L_PistolAmmo_ApplyButton->sizePolicy().hasHeightForWidth());
        L_PistolAmmo_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(L_PistolAmmo_ApplyButton);


        Change_Value->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        X_Posation_label = new QLabel(centralWidget);
        X_Posation_label->setObjectName(QString::fromUtf8("X_Posation_label"));
        X_Posation_label->setFont(font);

        horizontalLayout_3->addWidget(X_Posation_label);

        X_Posation_EditLine = new QLineEdit(centralWidget);
        X_Posation_EditLine->setObjectName(QString::fromUtf8("X_Posation_EditLine"));
        sizePolicy.setHeightForWidth(X_Posation_EditLine->sizePolicy().hasHeightForWidth());
        X_Posation_EditLine->setSizePolicy(sizePolicy);
        X_Posation_EditLine->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(X_Posation_EditLine);

        X_Posation_ApplyButton = new QPushButton(centralWidget);
        X_Posation_ApplyButton->setObjectName(QString::fromUtf8("X_Posation_ApplyButton"));
        sizePolicy1.setHeightForWidth(X_Posation_ApplyButton->sizePolicy().hasHeightForWidth());
        X_Posation_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(X_Posation_ApplyButton);


        Change_Value->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Y_Posation_label = new QLabel(centralWidget);
        Y_Posation_label->setObjectName(QString::fromUtf8("Y_Posation_label"));
        Y_Posation_label->setFont(font);

        horizontalLayout_4->addWidget(Y_Posation_label);

        Y_Posation_EditLine = new QLineEdit(centralWidget);
        Y_Posation_EditLine->setObjectName(QString::fromUtf8("Y_Posation_EditLine"));
        sizePolicy.setHeightForWidth(Y_Posation_EditLine->sizePolicy().hasHeightForWidth());
        Y_Posation_EditLine->setSizePolicy(sizePolicy);
        Y_Posation_EditLine->setMaximumSize(QSize(100, 20));

        horizontalLayout_4->addWidget(Y_Posation_EditLine);

        Y_Posation_ApplyButton = new QPushButton(centralWidget);
        Y_Posation_ApplyButton->setObjectName(QString::fromUtf8("Y_Posation_ApplyButton"));
        sizePolicy1.setHeightForWidth(Y_Posation_ApplyButton->sizePolicy().hasHeightForWidth());
        Y_Posation_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(Y_Posation_ApplyButton);


        Change_Value->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Z_Posation_label = new QLabel(centralWidget);
        Z_Posation_label->setObjectName(QString::fromUtf8("Z_Posation_label"));
        Z_Posation_label->setFont(font);

        horizontalLayout_5->addWidget(Z_Posation_label);

        Z_Posation_EditLine = new QLineEdit(centralWidget);
        Z_Posation_EditLine->setObjectName(QString::fromUtf8("Z_Posation_EditLine"));
        sizePolicy.setHeightForWidth(Z_Posation_EditLine->sizePolicy().hasHeightForWidth());
        Z_Posation_EditLine->setSizePolicy(sizePolicy);
        Z_Posation_EditLine->setMaximumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(Z_Posation_EditLine);

        Z_Posation_ApplyButton = new QPushButton(centralWidget);
        Z_Posation_ApplyButton->setObjectName(QString::fromUtf8("Z_Posation_ApplyButton"));
        sizePolicy1.setHeightForWidth(Z_Posation_ApplyButton->sizePolicy().hasHeightForWidth());
        Z_Posation_ApplyButton->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(Z_Posation_ApplyButton);


        Change_Value->addLayout(horizontalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LockHealth_checkBox = new QCheckBox(centralWidget);
        LockHealth_checkBox->setObjectName(QString::fromUtf8("LockHealth_checkBox"));
        LockHealth_checkBox->setFont(font);

        verticalLayout->addWidget(LockHealth_checkBox);

        LockAmmo_checkBox = new QCheckBox(centralWidget);
        LockAmmo_checkBox->setObjectName(QString::fromUtf8("LockAmmo_checkBox"));
        LockAmmo_checkBox->setFont(font);

        verticalLayout->addWidget(LockAmmo_checkBox);


        Change_Value->addLayout(verticalLayout);


        horizontalLayout_7->addLayout(Change_Value);

        Hitman5_ExternalClass->setCentralWidget(centralWidget);

        retranslateUi(Hitman5_ExternalClass);

        QMetaObject::connectSlotsByName(Hitman5_ExternalClass);
    } // setupUi

    void retranslateUi(QMainWindow *Hitman5_ExternalClass)
    {
        Hitman5_ExternalClass->setWindowTitle(QCoreApplication::translate("Hitman5_ExternalClass", "HITMAN 5 External Cheat", nullptr));
        Health_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Health         ", nullptr));
        Health_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        R_PistolAmmo_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "R_PistolAmmo", nullptr));
        R_PistolAmmo_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        L_PistolAmmo_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "L_PistolAmmo", nullptr));
        L_PistolAmmo_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        X_Posation_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "X Posation  ", nullptr));
        X_Posation_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        Y_Posation_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Y Posation  ", nullptr));
        Y_Posation_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        Z_Posation_label->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Z Posation  ", nullptr));
        Z_Posation_ApplyButton->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Apply", nullptr));
        LockHealth_checkBox->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Lock Health", nullptr));
        LockAmmo_checkBox->setText(QCoreApplication::translate("Hitman5_ExternalClass", "Lock Ammo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hitman5_ExternalClass: public Ui_Hitman5_ExternalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HITMAN5_EXTERNAL_H
