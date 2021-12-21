//
// Created by lc on 2021/12/21.
//

#include "NonBlockServerSocket.h"
#include <fcntl.h>

NonBlockServerSocket::NonBlockServerSocket()
: fd(socket(AF_INET, SOCK_STREAM, 0)) {
    if (fd < 0) {
        throw std::runtime_error("can not create socket fd");
    }
    fcntl(fd, F_SETFL, O_NONBLOCK);
}

NonBlockSocket NonBlockServerSocket::accept() {
    int connectedFD = ::accept(fd, reinterpret_cast<struct sockaddr*>(&temp), &socklen_t);
    return NonBlockSocket(connectedFD, temp);
}

void NonBlockServerSocket::bind(unsigned int port) const {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (::bind(fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        throw std::runtime_error("can not bind socket to port: " + std::to_string(port));
    }
}

void NonBlockServerSocket::listen(int backlog) const {
    if (::listen(fd, backlog) < 0) {
        throw std::runtime_error("can not listen");
    }
}