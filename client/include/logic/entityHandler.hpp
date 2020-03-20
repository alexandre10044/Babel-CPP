/*
** EPITECH PROJECT, 2019
** entityHandler.hpp
** File description:
** entityHandler
*/

#ifndef ENTITYHANDLER_HPP_
    #define ENTITYHANDLER_HPP_

    // # Lib Imports

    #include <vector>
    #include <string>

    // # Local Imports

    #include "../client.hpp"

    void HandleWelcome(std::vector<std::string> args, client *client);
    void HandleSuccessConnect(std::vector<std::string> args, client *client);
    void HandleFailConnect(std::vector<std::string> args, client *client);
    void HandlePendingSuccess(std::vector<std::string> args, client *client);
    void HandlePendingFail(std::vector<std::string> args, client *client);
    void HandlePendingInfo(std::vector<std::string> args, client *client);
    void HandleAddContact(std::vector<std::string> args, client *client);

#endif /* !ENTITYHANDLER_HPP_ */