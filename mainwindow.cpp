#include "mainwindow.h"
#include "ui_mainwindow.h"
QRegExp rd("(\\d+)");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menu_R->menuAction()->setVisible(false);
    ui->menu_1_R->menuAction()->setVisible(false);
    ui->menu_2_R->menuAction()->setVisible(false);
    ui->splitter->setStretchFactor(0,2);
    ui->splitter->setStretchFactor(1,3);
    ui->splitter->setStretchFactor(2,5);
    ui->splitter_2->setStretchFactor(0,7);
    ui->splitter_2->setStretchFactor(1,3);
    netmgr=new QNetworkAccessManager(this);
    connect(netmgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(funreply(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::httpPost(QString url,QString data){
    QNetworkRequest s;
    s.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    s.setUrl(QUrl(url));
    QByteArray payload;
    payload.append(data);
    netmgr->post(s,payload);
}

void MainWindow::httpGet(QString url){
    QNetworkRequest s;
    s.setUrl(QUrl(url));
    netmgr->get(s);
}

void MainWindow::funreply(QNetworkReply *reply)
{
    QString r=reply->readAll();
    dbgString=r;
    if(r.length()){
        if(r.indexOf("audio_iframe")>-1){
            //name="新书第11章.mp3" play_length="479000" voice_encode_fileid="MzI3OTI5MTYyOV8yMjQ3NTQ2MDg4"
            qDebug()<<"true";
            QRegExp rx("<mpvoice.+\\sname=\\\"(.+)\\\"\\s.+voice_encode_fileid=\\\"(.+)\\\"");
            rx.setMinimal(true);
            int c,pos=c=0;
            //ui->listWidget_3->clear();
            //sublst.clear();
            while((pos=rx.indexIn(r,pos))>-1){
                QString nm=rx.cap(1).replace("&nbsp;","");
                qDebug()<<c<<"("<<rx.cap(1)<<"),("<<rx.cap(2)<<")";
                QListWidgetItem *it=new QListWidgetItem();
                it->setText(nm);
                ui->listWidget_3->addItem(it);
                if(!disablePlay&&!c){
                    ui->axWidget->setProperty("URL",urlvoice+rx.cap(2));
                    ui->listWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
                    ui->listWidget_3->setCurrentItem(it);
                    ui->listWidget_3->setSelectionMode(QAbstractItemView::ExtendedSelection);
                }
                sublst[nm]=rx.cap(2);
                pos+=rx.matchedLength();
                c++;
            }
        }else{
            qDebug()<<"false";
            QRegExp rx("<a.+http://mp.weixin.qq.com/s.+</a>"),u("href=\\\"(.+)\\\""),qx(">(.+)</");
            u.setMinimal(true);
            rx.setMinimal(true);
            int pos=0;
            while((pos=rx.indexIn(r,pos))>-1){
                if(u.indexIn(rx.cap(0))>-1&&u.cap(1).indexOf("http")>-1){
                    lst.append(u.cap(1).replace("#wechat_redirect","").replace("&amp;","&")
                               .replace("http","https"));
                    QString nm=rx.cap(0).replace("&nbsp;","");
                    if(nm[0]=="<"){
                        while(qx.indexIn(nm)>-1){
                            nm=qx.cap(1);
                        }
                    }
                    nm=nm.replace(QRegExp("<.+>"),"").replace(" ","");
                    ui->listWidget_2->addItem(nm);
                }
                pos+=rx.matchedLength();
            }
        }
    }
}

void MainWindow::on_action_A_triggered()
{
    QMessageBox::about(this,"","温故而知新，可以为师矣\n故事播讲 谦儿2016\n程序 -by JuncoJet");
}

void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    if(lst.size()){
        disablePlay=false;
        qDebug()<<"open url:"<<lst[index.row()];
        httpGet(lst[index.row()]);
    }
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ui->listWidget_2->clear();
    lst.clear();
    httpGet(urlmp+urlparam[index.row()]);
}

void MainWindow::on_action_D_triggered()
{
    qDebug()<<dbgString;
}

void MainWindow::on_listWidget_2_customContextMenuRequested(const QPoint &pos)
{
    ui->menu_R->popup(QCursor::pos());
}

void MainWindow::on_listWidget_3_customContextMenuRequested(const QPoint &pos)
{
    ui->menu_2_R->popup(QCursor::pos());
}

void MainWindow::on_action_C_triggered()
{
    ui->listWidget_3->clear();
    sublst.clear();
}

void MainWindow::on_action_D_2_triggered()
{
    for(QListWidgetItem *i:ui->listWidget_3->selectedItems()){
        delete i;
    }
}

void MainWindow::on_action_A_2_triggered()
{
    exportPlaylst();
    if(ui->listWidget_3->count()>100)
        QMessageBox::warning(this,"","由于列表中文件过多，WMP播放器是个垃圾，可能不堪重负！\n"
                             "如果无法正常播放可以使用其他播放器手动打开目录中的 "+playlst+
                             "\n或者选择菜单“打开”->“外部播放器”来尝试播放");
    ui->axWidget->setProperty("URL",playlst);
}

void MainWindow::on_action_E_triggered()
{
    if(qApp->focusWidget()==ui->listWidget_3){
        exportPlaylst();
    }
    QMessageBox::information(this,"",playlst+" 导出完成！");
}

void MainWindow::exportPlaylst()
{
    QFile fp(playlst);
    if(fp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QTextStream s(&fp);
        s.setCodec("utf8");
        for(int i=0;i<ui->listWidget_3->count();i++){
            s<<urlvoice<<sublst[ui->listWidget_3->item(i)->text()]<<"\n";
        }
    }
    fp.close();
}

void MainWindow::on_action_P_triggered()
{
    disablePlay=false;
    if(qApp->focusWidget()==ui->listWidget_3){
        if(sublst.size()){
            ui->axWidget->setProperty("URL",urlvoice+sublst[ui->listWidget_3->currentItem()->text()]);
        }
    }else{
        if(lst.size()){
            qDebug()<<"open url:"<<lst[ui->listWidget_2->currentIndex().row()];
            httpGet(lst[ui->listWidget_2->currentIndex().row()]);
        }
    }
}

bool compFun(QString a,QString b)
{
    int ia=0,ib=0;
    if(rd.indexIn(a)!=-1)
        ia=rd.cap(1).toInt();
    if(rd.indexIn(b)!=-1)
        ib=rd.cap(1).toInt();
    if(ia&&ib)
        return ia<ib;
    else
        return a<b;
}

void MainWindow::on_action_S_2_triggered()
{
    //ui->listWidget_3->sortItems(Qt::AscendingOrder);
    QStringList l;
    for(int i=0;i<ui->listWidget_3->count();i++){
        l<<ui->listWidget_3->item(i)->text();
    }
    qSort(l.begin(),l.end(),compFun);
    ui->listWidget_3->clear();
    for(auto i:l)
        ui->listWidget_3->addItem(i);
}

void MainWindow::on_action_R_triggered()
{
    //ui->listWidget_3->sortItems(Qt::DescendingOrder);
    QStringList l;
    for(int i=0;i<ui->listWidget_3->count();i++){
        l<<ui->listWidget_3->item(i)->text();
    }
    qSort(l.begin(),l.end(),compFun);
    ui->listWidget_3->clear();
    for(auto it=l.rbegin();it!=l.rend();++it)
        ui->listWidget_3->addItem(*it);
}

void MainWindow::on_action_A_3_triggered()
{
    if(lst.size()){
        if(lst.size()>20)QMessageBox::warning(this,"","由于章节过多，需要耗费很长时间请耐心等待！");
        disablePlay=true;
        for(QStringList::reverse_iterator it=lst.rbegin();it!=lst.rend();++it)
            httpGet(*it);
    }
}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item)
{
    if(sublst.size()){
        ui->axWidget->setProperty("URL",urlvoice+sublst[item->text()]);
    }
}

void MainWindow::on_action_M_triggered()
{
    QSet<QString> s;
    for(int i=0;i<ui->listWidget_3->count();i++){
        s.insert(ui->listWidget_3->item(i)->text());
    }
    //去重后自动排序
    QStringList l;
    for(auto i:s)l<<i;
    qSort(l.begin(),l.end(),compFun);
    ui->listWidget_3->clear();
    for(auto i:l)
        ui->listWidget_3->addItem(i);
}

void MainWindow::on_action_P_2_triggered()
{
    exportPlaylst();
    ShellExecuteA(0,0,playlst.toUtf8(),0,0,1);
}

void MainWindow::on_action_S_3_triggered()
{
    disablePlay=true;
    if(lst.size()){
        for(int i=0;i<ui->listWidget_2->count();i++){
            if(ui->listWidget_2->item(i)->isSelected()){
                qDebug()<<i<<"open url:"<<lst[i];
                httpGet(lst[i]);
            }
        }
    }
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    ui->menu_1_R->popup(QCursor::pos());
}

void MainWindow::on_action_O_triggered()
{
    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected())
            ShellExecuteA(0,0,(urlmp+urlparam[i]).toUtf8(),0,0,1);
    }
}
