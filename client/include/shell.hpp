/*
** EPITECH PROJECT, 2019
** shell.hpp
** File description:
** shell
*/

#ifndef SHELL_HPP_
    #define SHELL_HPP_

    #include "client.hpp"
    #include "server.hpp"

    class shell {
        public:
            shell(client *, server *);
            ~shell();

            pthread_t thread;
            bool running;
            server *servInst;
            client *cl;

            void start();
            void stop();
            void shell_handler(std::vector<std::string>);
            char *shell_read_line(void);
    };


#endif /* !SHELL_HPP_ */