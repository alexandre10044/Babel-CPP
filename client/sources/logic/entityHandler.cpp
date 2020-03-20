/*
** EPITECH PROJECT, 2019
** entityHandler.cpp
** File description:
** entityHandler
*/

// # Lib Imports

#include <vector>
#include <string>
#include <iostream>

// # Local Imports

#include "../../include/logic/entityHandler.hpp"
#include "../../include/client.hpp"
#include "../../include/logic.hpp"
#include "../../include/actions.hpp"

// # Methods

// # 000 | Hello
void HandleWelcome(std::vector<std::string> args, client *client)
{
    client->state = WaitingForPseudo;
    actions *act = (actions*)client->act;
    (void)act;
    (void)args;
    //act->ConnectWithPseudo("azouz");
}

// # 002 | You are connected to the server successfully :)
void HandleSuccessConnect(std::vector<std::string> args, client *client)
{
    client->state = Connected;
    std::cout << "Server connection confirm :)" << std::endl;
    actions *act = (actions*)client->act;
    client->logged = true;
    (void)act;
    (void)args;
    //act->RequestFriend("bob");
}

// # 003 | Can't login with this username, someone is already connected.
void HandleFailConnect(std::vector<std::string> args, client *client)
{
    (void)args;
    client->state = ConnectionFailed;
    std::cout << "Server refuse connection for username, someone is already connected." << std::endl;
}

// # 008 {pseudo} | Friend invitation sent successfully !
void HandlePendingSuccess(std::vector<std::string> args, client *client)
{
    if (args.size() < 1)
        return;
    client->state = InvitationSent;
    std::cout << "Friend invitation sent successfully to " << args[0] << " !" << std::endl;
}

// # 009 {pseudo} | Can't found any use with this username
void HandlePendingFail(std::vector<std::string> args, client *client)
{
    if (args.size() < 1)
        return;
    client->state = InvitationFail;
    std::cout << "Can't found any use with the username : " << args[0] << std::endl;
}

// # 010 {pseudo} | Someone is asking for a friend invite
void HandlePendingInfo(std::vector<std::string> args, client *client)
{
    if (args.size() < 1)
        return;
    client->state = ReceivedFriendRequest;
    std::cout << args[0] << " sent a friend request !" << std::endl;
    actions *act = (actions*)client->act;
    (void)act;
    //act->AcceptFriend(args[0]);
}

// # 013 {address} {port} {pseudo} | Add a friend to the contacts list
void HandleAddContact(std::vector<std::string> args, client *client)
{
    if (args.size() < 3 || atoi(args[1].c_str()) <= 0)
        return;
    client->state = ContactAdded;
    contact *ct = new contact();
    ct->address = args[0];
    ct->port = atoi(args[1].c_str());
    ct->pseudo = args[2];
    client->contacts.push_back(ct);
    std::cout << "Received contact informations of your friend " << args[2] << std::endl;
}