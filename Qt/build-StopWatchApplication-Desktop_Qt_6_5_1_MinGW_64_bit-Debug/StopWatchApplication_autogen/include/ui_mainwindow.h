/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *startStopButton;
    QPushButton *resetButton;
    QPushButton *lapButton;
    QTextBrowser *lapsBrowser;
    QLabel *timeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(731, 373);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        startStopButton = new QPushButton(centralwidget);
        startStopButton->setObjectName("startStopButton");

        gridLayout->addWidget(startStopButton, 2, 0, 1, 1);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        gridLayout->addWidget(resetButton, 2, 1, 1, 1);

        lapButton = new QPushButton(centralwidget);
        lapButton->setObjectName("lapButton");

        gridLayout->addWidget(lapButton, 2, 2, 1, 1);

        lapsBrowser = new QTextBrowser(centralwidget);
        lapsBrowser->setObjectName("lapsBrowser");

        gridLayout->addWidget(lapsBrowser, 0, 2, 1, 1);

        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        timeLabel->setFont(font);
        timeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeLabel, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 731, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startStopButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        lapButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
