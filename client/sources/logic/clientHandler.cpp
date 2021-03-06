/*
** EPITECH PROJECT, 2019
** handler.cpp
** File description:
** handler
*/

// # Lib Imports

#include <iostream>
#include <vector>

// # Local Imports

#include "../../include/logic/clientHandler.hpp"
#include "../../include/logic.hpp"
#include "../../include/client.hpp"

// # Methods

static void (*clientHandlers[17])(std::vector<std::string> args, client *ent) = {
        HandleWelcome,
        NULL,
        HandleSuccessConnect,
        HandleFailConnect,
        NULL,
        NULL,
        NULL,
        NULL,
        HandlePendingSuccess,
        HandlePendingFail,
        HandlePendingInfo,
        NULL,
        NULL,
        HandleAddContact,
        NULL,
        NULL,
        NULL
    };

void dispatchPacket(int id, std::vector<std::string> args, client *ent)
{
    if (clientHandlers[id] == NULL)
        return;
    clientHandlers[id](args, ent);
}

void handlePacket(std::string data, client *ent)
{
    std::string token;
    std::vector<std::string> args;
    int size = 0;
    int id = -1;

    if (data.length() == 0)
        return;
    if (data.find(" ") != std::string::npos) {
        for (size_t pos = 0; (pos = data.find(" ")) != std::string::npos; size++) {
            std::string token = data.substr(0, pos);
            if (size == 0)
                id = manageId(token);
            else
                args.push_back(token);
            data.erase(0, pos + 1);
        }
        if (data.length())
            args.push_back(data);
    } else
        id = manageId(data);
    if (id >= 0 && id <= 17)
        dispatchPacket(id, args, ent);
}

int manageId(std::string data)
{
    if (data.length() == 0)
        return (-1);
    for (unsigned int i = 0; i < data.length(); i++)
        if (!(data[i] <= '9' && data[i] >= '0'))
            return (-1);
    int val = atoi(data.c_str());
    return (val);
}