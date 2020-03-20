/*
** EPITECH PROJECT, 2019
** callHandler.hpp
** File description:
** callHandler
*/

#ifndef CALLHANDLER_HPP_
    #define CALLHANDLER_HPP_

    // # Lib Imports

    #include <vector>
    #include <string>

    // # Local Imports

    #include "../entity.hpp"

    // # Methods

    void HandleCall(std::vector<std::string> args, entity *ent);
    void HandleAcceptCall(std::vector<std::string> args, entity *ent);
    void HandleHangUp(std::vector<std::string> args, entity *ent);
    void HandleCallData(std::vector<std::string> args, entity *ent);
    void HandleCallAcceptedCallBack(std::vector<std::string> args, entity *ent);

#endif /* !CALLHANDLER_HPP_ */