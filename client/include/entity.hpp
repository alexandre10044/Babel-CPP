/*
** EPITECH PROJECT, 2019
** client.hpp
** File description:
** client
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <vector>
    #include <string>
    #include <array>
    #include <boost/asio.hpp>
    #include <boost/array.hpp>

    class entity {
        public:
            entity(void *_serv, boost::asio::ip::tcp::socket *sock);
            ~entity();

            std::string pseudo;
            std::string address;
            boost::asio::io_service service;
            boost::asio::ip::tcp::socket *sock;
            boost::system::error_code error;
            std::array<char, 512> buffer;
            pthread_t thread;
            void *serv;
            void procData(std::string data);
            void openConnection(std::string addr, int port);
            void stop();
            void sendToClient(int id, std::vector<std::string> args);
            void handleData(std::string);
            void asyncReceive(void);
    };

#endif /* !ENTITY_HPP_ */