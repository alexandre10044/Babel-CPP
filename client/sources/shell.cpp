/*
** EPITECH PROJECT, 2019
** shell.cpp
** File description:
** shell
*/

// # Lib Imports
    
#include <iostream> 
#include <stack> 
#include <string.h>

// # Local Imports

#include "../include/shell.hpp"
#include "../include/actions.hpp"
#include "../include/entity.hpp"
#include "../include/client.hpp"

// # Static values

static const int read_size = 1024;

// # Builder

shell::shell(client *_cl, server *_sv)
{
    cl = _cl;
    servInst = _sv;
    running = false;
}

shell::~shell()
{ }

// # Methods

std::vector<std::string> split(const std::string &chaine, char delimiteur)
{
    std::vector<std::string> elements;
    std::stringstream ss(chaine);
    std::string sousChaine;

    while (getline(ss, sousChaine, delimiteur))
        elements.push_back(sousChaine);
    return (elements);
}

char *shell::shell_read_line(void)
{
    char *buff = (char *)malloc(sizeof(char) * read_size);
    int size = read_size;
    char curr;
    int pos = 0;

    if (!buff)
        return (NULL);
    while (true) {
        curr = getchar();
        if (!curr || -1 == curr || curr == '\n') {
            buff[pos] = '\0';
            return (buff);
        } else
            buff[pos] = curr;
        pos++;
        if (pos >= read_size) {
            size += read_size;
            buff = (char *)realloc(buff, size);
        }
    }
}

void shell::shell_handler(std::vector<std::string> elems)
{
    actions *act = (actions*)cl->act;

    if (elems.size() < 2 && (elems[0] == "login" ||
        elems[0] == "accept" || elems[0] == "refuse" ||
        elems[0] == "add" || elems[0] == "call")) {
        std::cout << "Invalid use of " << elems[0] << " command." << std::endl;
        return;
    }
    if (elems[0] == "login") {
        if (cl->logged) {
            std::cout << "You are already connected !" << std::endl;
            return;
        }
        act->ConnectWithPseudo(elems[1]);
        cl->pseudo = elems[1];
        return;
    }
    if (!cl->logged) {
        std::cout << "Please, connect to the server first." << std::endl;
        return;
    }
    if (elems[0] == "accept")
        act->AcceptFriend(elems[1]);
    if (elems[0] == "refuse")
        act->RefuseFriend(elems[1]);
    if (elems[0] == "add")
        act->RequestFriend(elems[1]);
    if (elems[0] == "call") {
        contact *ct = NULL;
        entity *ent = new entity(servInst, NULL);
        for (unsigned int i = 0; i < cl->contacts.size(); i++)
            if (cl->contacts[i]->pseudo == elems[1]) {
                ct = cl->contacts[i];
                break;
            }
        ent->pseudo = cl->pseudo;
        if (ct == NULL) {
            std::cout << "Can't find contact !" << std::endl;
            return;
        }
        ent->openConnection(ct->address, ct->port);
        servInst->clients.push_back(ent);
    }
    if (elems[0] == "acceptcall") {
        if (!servInst->clients.size())
            return;
        std::vector<std::string> vec;
        servInst->clients[0]->sendToClient(5, vec);
    }
    if (elems[0] == "closecall") {
        if (!servInst->clients.size())
            return;
        std::vector<std::string> vec;
        servInst->clients[0]->sendToClient(6, vec);
    }
}

void *shell_loop(void *obj)
{
    const char *invalid = "Invalid command. Please check syntax.";
    const char *prompt = "> ";
    shell *sh = (shell*)obj;
    char *command = NULL;

    while (sh->running) {
        std::cout << prompt;
        command = sh->shell_read_line();
        if (!command)
            break;
        std::vector<std::string> elems = split(command, ' ');
        if (elems.size() < 1) {
            std::cout << invalid << std::endl;
            continue;
        }
        sh->shell_handler(elems);
        if (command)
            free(command);
    }
    return (NULL);
}

void shell::start()
{
    if (running)
        return;
    running = true;
    pthread_create(&this->thread, NULL, shell_loop, (void *)this);
}

void shell::stop()
{
    if (!running)
        return;
    running = false;
}