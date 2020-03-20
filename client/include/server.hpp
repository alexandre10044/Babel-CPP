/*
** EPITECH PROJECT, 2019
** server.hpp
** File description:
** server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <vector>

    #include <boost/asio.hpp>
    #include <boost/array.hpp>
    #include "entity.hpp"
    #include "network.hpp"
    #include "logic/serverHandler.hpp"
    #include "audio.hpp"

    class server {
        public:
            std::vector<entity*> clients;
            network *net;
            bool running;
            audio *aud;

            server();
            ~server();
            entity *getClientByAddress(std::string);
            entity *getClientByPseudo(std::string);
            bool isPseudoAvailable(std::string);
            void acceptConnections();
            void handleClient();
            void stop();
    };



#endif /* !SERVER_HPP_ */