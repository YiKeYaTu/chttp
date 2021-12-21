//
// Created by lc on 2021/12/21.
//

#ifndef CHTTP_KQUEUEMULTIPLEXING_H
#define CHTTP_KQUEUEMULTIPLEXING_H

#include "AbstractMultiplexing.h"
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/fcntl.h>
#include <unistd.h>

class KQueueMultiplexing : public AbstractMultiplexing {
public:
    void addNonBlockSocket(const NonBlockSocket &nonBlockSocket) override;
    void addNonBlockServerSocket(const NonBlockServerSocket &nonBlockServerSocket) override;

    [[noreturn]] void start() override;

    KQueueMultiplexing();
private:
    const int fd;
    struct kevent events[100];

    NonBlockServerSocket serverSocket;
    std::vector<NonBlockSocket> clientSockets;

    void setEventByFD(int, void*);
};


#endif //CHTTP_KQUEUEMULTIPLEXING_H
