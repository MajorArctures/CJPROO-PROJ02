/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *Pomodoro;
    QWidget *pagePomodoro;
    QPushButton *btnStartPomodoro;
    QLabel *labelTimer;
    QProgressBar *progressPomodoro;
    QPushButton *btnPausePomodoro;
    QPushButton *btnResetPomodoro;
    QPushButton *btnConfig;
    QLabel *labelStatus;
    QWidget *pageConfig;
    QPushButton *btnGoBack;
    QWidget *gridLayoutWidget_2;
    QGridLayout *TimeShortBreak;
    QTimeEdit *timeSB;
    QLabel *timeSBL;
    QWidget *gridLayoutWidget;
    QGridLayout *PomodoroTime;
    QTimeEdit *timePom;
    QLabel *timePomL;
    QWidget *gridLayoutWidget_3;
    QGridLayout *TimeLongBreak;
    QTimeEdit *timeLB;
    QLabel *timeLBL;
    QMenuBar *menubar;
    QMenu *menuPomodoroProject;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(583, 422);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Pomodoro = new QStackedWidget(centralwidget);
        Pomodoro->setObjectName("Pomodoro");
        Pomodoro->setGeometry(QRect(0, 10, 581, 401));
        pagePomodoro = new QWidget();
        pagePomodoro->setObjectName("pagePomodoro");
        btnStartPomodoro = new QPushButton(pagePomodoro);
        btnStartPomodoro->setObjectName("btnStartPomodoro");
        btnStartPomodoro->setGeometry(QRect(80, 50, 141, 31));
        labelTimer = new QLabel(pagePomodoro);
        labelTimer->setObjectName("labelTimer");
        labelTimer->setGeometry(QRect(30, 80, 271, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(72);
        labelTimer->setFont(font);
        labelTimer->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        labelTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressPomodoro = new QProgressBar(pagePomodoro);
        progressPomodoro->setObjectName("progressPomodoro");
        progressPomodoro->setGeometry(QRect(30, 212, 271, 31));
        progressPomodoro->setValue(24);
        btnPausePomodoro = new QPushButton(pagePomodoro);
        btnPausePomodoro->setObjectName("btnPausePomodoro");
        btnPausePomodoro->setGeometry(QRect(40, 270, 91, 31));
        btnResetPomodoro = new QPushButton(pagePomodoro);
        btnResetPomodoro->setObjectName("btnResetPomodoro");
        btnResetPomodoro->setGeometry(QRect(180, 270, 101, 31));
        btnConfig = new QPushButton(pagePomodoro);
        btnConfig->setObjectName("btnConfig");
        btnConfig->setGeometry(QRect(400, 310, 161, 41));
        labelStatus = new QLabel(pagePomodoro);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(20, 10, 271, 31));
        labelStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Pomodoro->addWidget(pagePomodoro);
        pageConfig = new QWidget();
        pageConfig->setObjectName("pageConfig");
        btnGoBack = new QPushButton(pageConfig);
        btnGoBack->setObjectName("btnGoBack");
        btnGoBack->setGeometry(QRect(400, 310, 151, 41));
        gridLayoutWidget_2 = new QWidget(pageConfig);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 250, 161, 80));
        TimeShortBreak = new QGridLayout(gridLayoutWidget_2);
        TimeShortBreak->setObjectName("TimeShortBreak");
        TimeShortBreak->setContentsMargins(0, 0, 0, 0);
        timeSB = new QTimeEdit(gridLayoutWidget_2);
        timeSB->setObjectName("timeSB");

        TimeShortBreak->addWidget(timeSB, 1, 0, 1, 1);

        timeSBL = new QLabel(gridLayoutWidget_2);
        timeSBL->setObjectName("timeSBL");
        timeSBL->setAlignment(Qt::AlignmentFlag::AlignCenter);

        TimeShortBreak->addWidget(timeSBL, 0, 0, 1, 1);

        gridLayoutWidget = new QWidget(pageConfig);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 50, 161, 80));
        PomodoroTime = new QGridLayout(gridLayoutWidget);
        PomodoroTime->setObjectName("PomodoroTime");
        PomodoroTime->setContentsMargins(0, 0, 0, 0);
        timePom = new QTimeEdit(gridLayoutWidget);
        timePom->setObjectName("timePom");

        PomodoroTime->addWidget(timePom, 1, 0, 1, 1);

        timePomL = new QLabel(gridLayoutWidget);
        timePomL->setObjectName("timePomL");
        timePomL->setAlignment(Qt::AlignmentFlag::AlignCenter);

        PomodoroTime->addWidget(timePomL, 0, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(pageConfig);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(20, 150, 161, 80));
        TimeLongBreak = new QGridLayout(gridLayoutWidget_3);
        TimeLongBreak->setObjectName("TimeLongBreak");
        TimeLongBreak->setContentsMargins(0, 0, 0, 0);
        timeLB = new QTimeEdit(gridLayoutWidget_3);
        timeLB->setObjectName("timeLB");

        TimeLongBreak->addWidget(timeLB, 1, 0, 1, 1);

        timeLBL = new QLabel(gridLayoutWidget_3);
        timeLBL->setObjectName("timeLBL");
        timeLBL->setAlignment(Qt::AlignmentFlag::AlignCenter);

        TimeLongBreak->addWidget(timeLBL, 0, 0, 1, 1);

        Pomodoro->addWidget(pageConfig);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 583, 21));
        menuPomodoroProject = new QMenu(menubar);
        menuPomodoroProject->setObjectName("menuPomodoroProject");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPomodoroProject->menuAction());

        retranslateUi(MainWindow);

        Pomodoro->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnStartPomodoro->setText(QCoreApplication::translate("MainWindow", "START!", nullptr));
        labelTimer->setText(QCoreApplication::translate("MainWindow", "TIME", nullptr));
        btnPausePomodoro->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        btnResetPomodoro->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        btnConfig->setText(QCoreApplication::translate("MainWindow", "Configurations", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        btnGoBack->setText(QCoreApplication::translate("MainWindow", "READY!", nullptr));
        timeSBL->setText(QCoreApplication::translate("MainWindow", "Short Break Time", nullptr));
        timePomL->setText(QCoreApplication::translate("MainWindow", "Pomodoro Time", nullptr));
        timeLBL->setText(QCoreApplication::translate("MainWindow", "Long Break Time", nullptr));
        menuPomodoroProject->setTitle(QCoreApplication::translate("MainWindow", "PomodoroProject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
