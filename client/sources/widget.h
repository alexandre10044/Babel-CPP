#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QUdpSocket>
#include <map>
#include <string>

#include "../include/server.hpp"
#include "../include/client.hpp"
#include "../include/shell.hpp"
#include "../include/actions.hpp"



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QUdpSocket *_socket;
    server *servInst;
    client *cl;
    shell *sh;
    
    void initSocket();
    void readPendingDatagrams();

private slots:
    void on_pushButton_call_clicked();
    void on_pushButton_Add_clicked();
    void on_pushButton_hang_up_clicked();
    void on_pushButton_ConnectMe_clicked();
    void box_Friends();

private:
    Ui::Widget *ui;
    std::map<std::string, std::pair<std::string, uint>> _contacts; // ["pseudo"] = ("ip", port)
};

#endif // WIDGET_H
