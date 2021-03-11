#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QRegExp>
#include <QFile>
#include <QListWidgetItem>
#include <QThread>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void httpPost(QString url,QString data);
    void httpGet(QString url);
    QString urlmp="https://mp.weixin.qq.com/s/",urlvoice="https://res.wx.qq.com/voice/getvoice?mediaid=";
    QStringList urlparam={"uzxGzhWKNrNutvATzJzLvQ","3V0gefCyYWKs6ALe0wYFOw","l-LP-GerIdN0Ec8uaY9vQQ"};
    QString dbgString,playlst="playlist.m3u";
    QStringList lst;
    QHash<QString,QString> sublst;

private slots:
    void funreply(QNetworkReply *reply);

    void on_action_A_triggered();

    void on_listWidget_2_doubleClicked(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_action_D_triggered();

    void on_listWidget_2_customContextMenuRequested(const QPoint &pos);

    void on_listWidget_3_customContextMenuRequested(const QPoint &pos);

    void on_action_C_triggered();

    void on_action_D_2_triggered();

    void on_action_A_2_triggered();

    void on_action_E_triggered();

    void on_action_P_triggered();

    void on_action_S_2_triggered();

    void on_action_R_triggered();

    void on_action_A_3_triggered();

    void on_listWidget_3_itemDoubleClicked(QListWidgetItem *item);

    void on_action_M_triggered();

    void on_action_P_2_triggered();

    void on_action_S_3_triggered();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_action_O_triggered();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *netmgr;
    void exportPlaylst();
    bool disablePlay;
};

#endif // MAINWINDOW_H
