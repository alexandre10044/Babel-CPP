/*
** EPITECH PROJECT, 2019
** handler.hpp
** File description:
** handler
*/

#ifndef HANDLER_HPP_
    #define HANDLER_HPP_

    #include <string>
    #include <vector>

    #include "../client.hpp"

    void dispatchPacket(int id, std::vector<std::string> args, client *ent);
    void handlePacket(std::string data, client *ent);
    int manageId(std::string data);

#endif /* !HANDLER_HPP_ */