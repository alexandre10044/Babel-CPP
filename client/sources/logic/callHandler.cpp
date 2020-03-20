/*
** EPITECH PROJECT, 2019
** callHandler.cpp
** File description:
** callHandler
*/

// # Lib Imports

#include <vector>
#include <string>
#include <iostream>

// # Local Imports

#include "../../include/logic/callHandler.hpp"
#include "../../include/entity.hpp"
#include "../../include/logic.hpp"
#include "../../include/server.hpp"

// # Methods

// # 004 {pseudo} | Someone is calling you
void HandleCall(std::vector<std::string> args, entity *ent)
{
    (void)args;
    server *serv = (server*)ent->serv;
    if (args.size() < 1 || serv->aud->inCall)
        return;
    std::cout << args[0] << " is calling you !" << std::endl;
}

// # 005 | Call accepted
void HandleAcceptCall(std::vector<std::string> args, entity *ent)
{
    (void)args;
    server *serv = (server*)ent->serv;
    std::vector<std::string> vec;
    std::cout << "Call accepted !" << std::endl;
    ent->sendToClient(CallAcceptCallBack, vec);
    std::cout << "You are in call !" << std::endl;
    serv->aud->startCall();
}

// # 006 | Call closed
void HandleHangUp(std::vector<std::string> args, entity *ent)
{
    (void)args;
    server *serv = (server*)ent->serv;
    std::cout << "Call closed !" << std::endl;
    serv->aud->stopCall();
}

// # 014 {data} | Call data
void HandleCallData(std::vector<std::string> args, entity *ent)
{
    server *serv = (server*)ent->serv;
    if (args.size() < 1 || !serv->aud->inCall)
        return;
    std::cout << "Call data received..." << std::endl;
    serv->aud->handleData(args[0]);
}

// # 015 | Call Accepted Call Back
void HandleCallAcceptedCallBack(std::vector<std::string> args, entity *ent)
{
    (void)args;
    server *serv = (server*)ent->serv;
    std::cout << "You are in call !" << std::endl;
    serv->aud->startCall();
}