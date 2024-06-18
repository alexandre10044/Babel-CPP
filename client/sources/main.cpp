/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

// # Lib Imports

#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <boost/thread.hpp>
#include <QApplication>
// # Local Imports

#include "../include/client.hpp"
#include "../include/server.hpp"
#include "../include/shell.hpp"
#include "widget.h"

// # Static values

static const int success = 0;
static const int fail = 84;
static server *servInst;
static client *cl;
static shell *sh;

// # Methods

void my_handler(int s)
{
    if (servInst == NULL || cl == NULL)
        return;
    if (servInst->aud->inCall) {
        servInst->aud->stopCall();
        std::cout << "Call ended by local user." << std::endl;
        if (!servInst->clients.size())
            return;
        std::vector<std::string> vec;
        servInst->clients[0]->sendToClient(6, vec);
        return;
    }
    std::cout << "Shuting down..." << std::endl;
    (void)s;
    try {
        servInst->stop();
        cl->stop();
        sh->stop();
    } catch(std::exception ex) {}
    exit(0);
}

int main(int ac, char **as)
{
    struct sigaction sigIntHandler;
    QApplication a(ac, as);
    Widget w;

    srand((unsigned int)time(NULL));
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    servInst = w.servInst;
    cl = w.cl;
    sh = w.sh;
    w.show();
    return (a.exec());
}