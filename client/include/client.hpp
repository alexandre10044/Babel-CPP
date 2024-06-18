/*
** EPITECH PROJECT, 2019
** client.hpp
** File description:
** client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <string>
    #include <boost/asio.hpp>
    #include <boost/array.hpp>

    enum client_state {
        None = 0,
        WaitingForPseudo,
        Connected,
        ConnectionFailed,
        InvitationSent,
        InvitationFail,
        ReceivedFriendRequest,
        ContactAdded
    };

    class actions;

    class contact {
        public:
            std::string address;
            int port;
            std::string pseudo;
    };

    class client {
        public:
            client(int port);
            ~client();

            boost::asio::io_service service;
            boost::asio::ip::tcp::socket *sock;
            boost::system::error_code error;
            std::array<char, 512> buffer;
            std::vector<contact*> contacts;
            enum client_state state;
            actions *act;
            int port;
            std::string pseudo;

            bool logged;
            pthread_t thread;
            void stop();
            void procData(std::string data);
            void openConnection();
            void handleData(std::string data);
            void asyncReceive();
            void sendToServer(int id, std::vector<std::string> args);
    };


#endif /* !CLIENT_HPP_ */