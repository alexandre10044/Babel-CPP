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

    #include "../entity.hpp"

    void servDispatchPacket(int id, std::vector<std::string> args, entity *ent);
    void servHandlePacket(std::string data, entity *ent);
    int servManageId(std::string data);

#endif /* !HANDLER_HPP_ */