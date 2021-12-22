//
// Created by lc on 2021/12/21.
//

#ifndef CHTTP_ABSTRACTMULTIPLEXING_H
#define CHTTP_ABSTRACTMULTIPLEXING_H

#include "NonBlockServerSocket.h"
#include "NonBlockSocket.h"

class AbstractMultiplexing {
public:
    void onRead(const std::function<void(NonBlockSocket& nonBlockSocket)>& handleRead) { this->handleRead = handleRead; }
    void onClose(const std::function<void(NonBlockSocket& nonBlockSocket)>& handleClose) { this->handleClose = handleClose; }
    void onAccept(const std::function<void(NonBlockServerSocket& nonBlockServerSocket)>& handleAccept) { this->handleAccept = handleAccept; }

    virtual void addNonBlockServerSocket(const NonBlockServerSocket& nonBlockServerSocket) = 0;
    virtual void addNonBlockSocket(const NonBlockSocket& nonBlockSocket) = 0;
    virtual void closeNonBlockSocket(const NonBlockSocket &nonBlockSocket) = 0;

    virtual void start() = 0;

protected:
    std::function<void(NonBlockSocket& nonBlockSocket)> handleRead;
    std::function<void(NonBlockSocket& nonBlockSocket)> handleClose;
    std::function<void(NonBlockServerSocket& nonBlockServerSocket)> handleAccept;
};


#endif //CHTTP_ABSTRACTMULTIPLEXING_H
