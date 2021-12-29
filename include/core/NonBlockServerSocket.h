//
// Created by lc on 2021/12/21.
//

#ifndef CHTTP_NONBLOCKSERVERSOCKET_H
#define CHTTP_NONBLOCKSERVERSOCKET_H

#include <memory>
#include "NonBlockSocket.h"

class KQueueMultiplexing;

class NonBlockServerSocket {
    friend class KQueueMultiplexing;
public:
    NonBlockServerSocket();
    NonBlockSocket accept();
    void bind(unsigned int) const;
    void listen(int = 1000) const;
private:
    int fd;
    sockaddr_in temp;
    socklen_t socklen_t;
};


#endif //CHTTP_NONBLOCKSERVERSOCKET_H
