/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_A;
    QAction *action_H;
    QAction *action_H_2;
    QAction *action_D;
    QAction *action_S;
    QAction *action_P;
    QAction *action_S_2;
    QAction *action_R;
    QAction *action_A_2;
    QAction *action_E;
    QAction *action_C;
    QAction *action_D_2;
    QAction *action_A_3;
    QAction *action_M;
    QAction *action_P_2;
    QAction *action_S_3;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;
    QAxWidget *axWidget;
    QMenuBar *menuBar;
    QMenu *menu_S;
    QMenu *menu_H;
    QMenu *menu_O;
    QMenu *menu_R;
    QMenu *menu_2_R;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        action_A = new QAction(MainWindow);
        action_A->setObjectName(QStringLiteral("action_A"));
        action_H = new QAction(MainWindow);
        action_H->setObjectName(QStringLiteral("action_H"));
        action_H_2 = new QAction(MainWindow);
        action_H_2->setObjectName(QStringLiteral("action_H_2"));
        action_D = new QAction(MainWindow);
        action_D->setObjectName(QStringLiteral("action_D"));
        action_S = new QAction(MainWindow);
        action_S->setObjectName(QStringLiteral("action_S"));
        action_P = new QAction(MainWindow);
        action_P->setObjectName(QStringLiteral("action_P"));
        action_S_2 = new QAction(MainWindow);
        action_S_2->setObjectName(QStringLiteral("action_S_2"));
        action_R = new QAction(MainWindow);
        action_R->setObjectName(QStringLiteral("action_R"));
        action_A_2 = new QAction(MainWindow);
        action_A_2->setObjectName(QStringLiteral("action_A_2"));
        action_E = new QAction(MainWindow);
        action_E->setObjectName(QStringLiteral("action_E"));
        action_C = new QAction(MainWindow);
        action_C->setObjectName(QStringLiteral("action_C"));
        action_D_2 = new QAction(MainWindow);
        action_D_2->setObjectName(QStringLiteral("action_D_2"));
        action_A_3 = new QAction(MainWindow);
        action_A_3->setObjectName(QStringLiteral("action_A_3"));
        action_M = new QAction(MainWindow);
        action_M->setObjectName(QStringLiteral("action_M"));
        action_P_2 = new QAction(MainWindow);
        action_P_2->setObjectName(QStringLiteral("action_P_2"));
        action_S_3 = new QAction(MainWindow);
        action_S_3->setObjectName(QStringLiteral("action_S_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        splitter->addWidget(listWidget);
        listWidget_2 = new QListWidget(splitter);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection);
        splitter->addWidget(listWidget_2);
        listWidget_3 = new QListWidget(splitter);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_3->setDragDropMode(QAbstractItemView::InternalMove);
        listWidget_3->setSelectionMode(QAbstractItemView::ExtendedSelection);
        splitter->addWidget(listWidget_3);
        splitter_2->addWidget(splitter);
        axWidget = new QAxWidget(splitter_2);
        axWidget->setControl(QStringLiteral("{6bf52a52-394a-11d3-b153-00c04f79faa6}"));
        axWidget->setObjectName(QStringLiteral("axWidget"));
        splitter_2->addWidget(axWidget);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu_S = new QMenu(menuBar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        menu_R = new QMenu(menuBar);
        menu_R->setObjectName(QStringLiteral("menu_R"));
        menu_2_R = new QMenu(menuBar);
        menu_2_R->setObjectName(QStringLiteral("menu_2_R"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_O->menuAction());
        menuBar->addAction(menu_S->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuBar->addAction(menu_R->menuAction());
        menuBar->addAction(menu_2_R->menuAction());
        menu_S->addAction(action_H);
        menu_S->addAction(action_S);
        menu_H->addAction(action_A);
        menu_O->addAction(action_H_2);
        menu_O->addAction(action_D);
        menu_O->addAction(action_P_2);
        menu_R->addAction(action_P);
        menu_R->addSeparator();
        menu_R->addAction(action_S_3);
        menu_R->addAction(action_A_3);
        menu_2_R->addAction(action_P);
        menu_2_R->addAction(action_A_2);
        menu_2_R->addSeparator();
        menu_2_R->addAction(action_D_2);
        menu_2_R->addAction(action_M);
        menu_2_R->addAction(action_C);
        menu_2_R->addSeparator();
        menu_2_R->addAction(action_E);
        menu_2_R->addSeparator();
        menu_2_R->addAction(action_S_2);
        menu_2_R->addAction(action_R);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QianErPlayer \344\273\231\351\243\216\351\201\223\351\252\250\347\211\210", Q_NULLPTR));
        action_A->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        action_H->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\222\255\346\224\276\345\216\206\345\217\262(&H)", Q_NULLPTR));
        action_H_2->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276\345\216\206\345\217\262(&H)", Q_NULLPTR));
        action_D->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\347\252\227\345\217\243(&D)", Q_NULLPTR));
        action_S->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\351\207\215\346\216\222\345\272\217(&S)", Q_NULLPTR));
        action_P->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276(&P)", Q_NULLPTR));
        action_S_2->setText(QApplication::translate("MainWindow", "\346\255\243\345\272\217\346\216\222\345\272\217(&S)", Q_NULLPTR));
        action_R->setText(QApplication::translate("MainWindow", "\345\217\215\345\272\217\346\216\222\345\272\217(&R)", Q_NULLPTR));
        action_A_2->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276\345\205\250\351\203\250(&A)", Q_NULLPTR));
        action_E->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\222\255\346\224\276\345\215\225(&E)", Q_NULLPTR));
        action_C->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\210\227\350\241\250(&C)", Q_NULLPTR));
        action_D_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\351\200\211\344\270\255(&D)", Q_NULLPTR));
        action_A_3->setText(QApplication::translate("MainWindow", "\346\213\211\345\217\226\345\205\250\351\203\250(&A)", Q_NULLPTR));
        action_M->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\351\207\215\345\244\215(&M)", Q_NULLPTR));
        action_P_2->setText(QApplication::translate("MainWindow", "\345\244\226\351\203\250\346\222\255\346\224\276\345\231\250(&P)", Q_NULLPTR));
        action_S_3->setText(QApplication::translate("MainWindow", "\346\213\211\345\217\226\351\200\211\344\270\255(&S)", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\344\277\256\344\273\231", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "\346\211\223\350\204\270", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "\346\226\260\344\271\246", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        menu_S->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_O->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
        menu_R->setTitle(QApplication::translate("MainWindow", "\345\217\263\351\224\256(&R)", Q_NULLPTR));
        menu_2_R->setTitle(QApplication::translate("MainWindow", "\345\217\263\351\224\2562(R)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
