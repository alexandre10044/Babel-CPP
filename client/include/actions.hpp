/*
** EPITECH PROJECT, 2019
** actions.hpp
** File description:
** actions
*/

#ifndef ACTIONS_HPP_
    #define ACTIONS_HPP_

    #include <string>
    #include <boost/asio.hpp>
    #include <boost/array.hpp>

    #include "client.hpp"

    class actions {
        public:
            actions(client *cl);
            ~actions();

            client *cl;
            void ConnectWithPseudo(std::string pseudo);
            void RequestFriend(std::string pseudo);
            void AcceptFriend(std::string pseudo);
            void RefuseFriend(std::string pseudo);
    };


#endif /* !ACTIONS_HPP_ */