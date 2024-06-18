/*
** EPITECH PROJECT, 2019
** actions.cpp
** File description:
** actions
*/

#include "../include/actions.hpp"
#include "../include/logic.hpp"

actions::actions(client *_cl)
{
    cl = _cl;
}

actions::~actions()
{

}

void actions::ConnectWithPseudo(std::string pseudo)
{
    std::vector<std::string> vec;
    vec.push_back(pseudo);
    cl->sendToServer(Connect, vec);
}

void actions::RequestFriend(std::string pseudo)
{
    std::vector<std::string> vec;
    vec.push_back(pseudo);
    cl->sendToServer(PendingRequest, vec);
}

void actions::AcceptFriend(std::string pseudo)
{
    std::vector<std::string> vec;
    vec.push_back(pseudo);
    cl->sendToServer(AcceptPending, vec);
}

void actions::RefuseFriend(std::string pseudo)
{
    std::vector<std::string> vec;
    vec.push_back(pseudo);
    cl->sendToServer(RefusePending, vec);
}