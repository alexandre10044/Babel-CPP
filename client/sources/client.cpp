/*
** EPITECH PROJECT, 2019
** client.cpp
** File description:
** client
*/

#include <iostream>
#include <bits/stdc++.h>

#include "../include/client.hpp"
#include "../include/actions.hpp"
#include "../include/logic/clientHandler.hpp"
#include "../include/audio.hpp"

client::client(int p)
{
    state = None;
    act = new actions(this);
    port = p;
    logged = false;
}

client::~client()
{
    stop();
}

static void *task(void *obj)
{
    client *cl = (client*)obj;
    cl->asyncReceive();
    cl->service.run();
    return (NULL);
}

void client::openConnection()
{
    boost::asio::ip::tcp::endpoint ep(
        boost::asio::ip::address::from_string("127.0.0.1"), 2000);
    sock = new boost::asio::ip::tcp::socket(service);
    sock->connect(ep, error);
    if (error) {
        std::cout << "Can't open connection to server." << std::endl;
        exit(0);
    } else {
        std::vector<std::string> vec;
        vec.push_back(std::to_string(port));
        sendToServer(0, vec);
        std::cout << "Connected to server." << std::endl;
        pthread_create(&this->thread, NULL, task, (void *)this);
    }
}

void client::handleData(std::string data)
{
    handlePacket(data, this);
}

void client::procData(std::string data)
{
    const size_t length = data.size();
    for (size_t i = 0; i < length; ++i)
        printf("%3d (0x%02X)\n", data[i], data[i]);
    std::cout << "#Binary data : ";
    for (std::size_t i = 0; i < data.size(); ++i)
        std::cout << std::bitset<8>(data.c_str()[i]) << std::endl;
    std::cout << "#Clear data : " << data << std::endl;
}

void client::asyncReceive()
{
    sock->async_receive(boost::asio::buffer(buffer, 512), [this](const boost::system::error_code &error, std::size_t bytesTransfered) {
        if (error != boost::system::errc::success) {
            std::cout << "Connection lost with server." << std::endl;
            return;
        } else {
            std::string data;
            for (unsigned int i = 0; i < bytesTransfered && buffer[i]; i++)
                data += buffer[i];
            std::cout << "Received: ";
            procData(data);
            handleData(data);
        }
        asyncReceive();
    });
}

void client::sendToServer(int id, std::vector<std::string> args)
{
    std::string val = std::to_string(id);
    for (unsigned int i = 0; i < args.size(); i++)
        val += " " + args[i];
    std::cout << "Sent: ";
    procData(val);
    sock->send(boost::asio::buffer(val, val.length()));
}

void client::stop()
{
    sock->close();
    service.stop();
}