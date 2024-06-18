/*
** EPITECH PROJECT, 2019
** server.cpp
** File description:
** server
*/

// # Lib Imports

// # Local Imports

#include "../include/server.hpp"
#include "../include/network.hpp"
#include "../include/logic/serverHandler.hpp"

// # Builder / Destructor

server::server()
{
    net = new network(this);
    aud = new audio();
}

server::~server()
{
    stop();
}

// # Methods

entity *server::getClientByAddress(std::string address)
{
    for (unsigned int i = 0; i < clients.size(); i++)
        if (clients[i]->address == address)
            return (clients[i]);
    return (NULL);
}

entity *server::getClientByPseudo(std::string pseudo)
{
    for (unsigned int i = 0; i < clients.size(); i++)
        if (clients[i]->pseudo == pseudo)
            return (clients[i]);
    return (NULL);
}

bool server::isPseudoAvailable(std::string pseudo)
{
    for (unsigned int i = 0; i < clients.size(); i++)
        if (clients[i]->pseudo == pseudo)
            return (false);
    return (true);
}         

void server::acceptConnections()
{
    running = true;
    net->start();
}

void server::handleClient()
{
    std::cout << "Friend connected to call server" << std::endl;
    clients.push_back(new entity(this, net->sockets.back()));
    net->sockets.pop_back();
}

void server::stop()
{
    net->stop();
    running = false;
    while (clients.size() != 0) {
        entity *entity = clients.back();
        entity->stop();
        clients.pop_back();
    }
}