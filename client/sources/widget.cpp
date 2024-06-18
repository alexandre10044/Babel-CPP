#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include <QMessageBox>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _socket = new QUdpSocket(this);
    servInst = new server();
    servInst->acceptConnections();
    usleep(500000);
    cl = new client(servInst->net->port);
    cl->openConnection();
    usleep(500000);
    sh = new shell(cl, servInst);
    sh->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initSocket()
{
    _socket = new QUdpSocket(this);
    _socket->bind(QHostAddress::LocalHost, 7755);
}

void Widget::readPendingDatagrams()
{
    while (_socket->hasPendingDatagrams())
        QNetworkDatagram datagram = _socket->receiveDatagram();
}

void Widget::on_pushButton_call_clicked()
{
    QListWidgetItem *item = ui->listWidget_contacts->currentItem();
    if (item == NULL) {
        if (!servInst->clients.size())
        return;
        std::vector<std::string> vec;
        servInst->clients[0]->sendToClient(5, vec);
        return;
    }
    QString data = item->text();
    std::string val = data.toUtf8().constData();

    if (servInst->clients.size()) {
        std::vector<std::string> vec;
        servInst->clients[0]->sendToClient(5, vec);
        return;
    }
    if (!item) {
        QMessageBox::information(NULL, "Call", "No contact selected.");
        return;
    }
    contact *ct = NULL;
    entity *ent = new entity(servInst, NULL);
    for (unsigned int i = 0; i < cl->contacts.size(); i++)
        if (cl->contacts[i]->pseudo == val) {
            ct = cl->contacts[i];
            break;
        }
    ent->pseudo = cl->pseudo;
    if (ct == NULL) {
        std::cout << "Can't find contact !" << std::endl;
        return;
    }
    ent->openConnection(ct->address, ct->port);
    servInst->clients.push_back(ent);
}

void Widget::on_pushButton_hang_up_clicked()
{
    if (!servInst->clients.size())
        return;
    std::vector<std::string> vec;
    servInst->clients[0]->sendToClient(6, vec);
}


void Widget::on_pushButton_ConnectMe_clicked()
{
    QString data = ui->box_Pseudo->toPlainText();
    std::string val = data.toUtf8().constData();

    if (val.size() == 0) {
        return;
    }
    if (cl->logged) {
        std::cout << "You are already connected !" << std::endl;
        return;
    }
    cl->act->ConnectWithPseudo(val);
    cl->pseudo = val;
}

void Widget::box_Friends()
{

}
void Widget::on_pushButton_Add_clicked()
{
    if (!cl->logged)
        return;
    QString data = ui->box_Friends->toPlainText();
    std::string val = data.toUtf8().constData();

    if (val.size() == 0) {
        return;
    }
    cl->act->AcceptFriend(val);
    cl->act->RequestFriend(val);
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(data);
    ui->listWidget_contacts->insertItem(0, newItem);
}