
//
// Created by lc on 2021/12/21.
//

#ifndef CHTTP_SOCKET_H
#define CHTTP_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <memory>
#include <vector>

class KQueueMultiplexing;

class NonBlockSocket {
    friend class KQueueMultiplexing;
public:
    int readFromSocket(std::shared_ptr<char[]>, ssize_t) const;
    int writeToSocket(std::shared_ptr<char[]>, ssize_t) const;
    NonBlockSocket(const ssize_t&, struct sockaddr_in&) ;

protected:
    ssize_t fd;
    struct sockaddr_in address;
private:
    int closeSocket() const;
};


#endif //CHTTP_SOCKET_H
