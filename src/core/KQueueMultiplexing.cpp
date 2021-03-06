//
// Created by lc on 2021/12/21.
//

#include "core/KQueueMultiplexing.h"

KQueueMultiplexing::KQueueMultiplexing()
: fd(kqueue()) {}

void KQueueMultiplexing::setEventByFD(int socketFD, void* extraDataPointer) {
    struct kevent e;
    EV_SET(&e, socketFD, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, extraDataPointer);
    kevent(fd, &e, 1, NULL, 0, NULL);
}

void KQueueMultiplexing::addNonBlockSocket(const NonBlockSocket &nonBlockSocket) {
    nonBlockSocketsMap.insert(std::pair(nonBlockSocket.fd, nonBlockSocket));
    setEventByFD(nonBlockSocket.fd, &nonBlockSocketsMap.find(nonBlockSocket.fd)->second);
}

void KQueueMultiplexing::addNonBlockServerSocket(const NonBlockServerSocket &nonBlockServerSocket) {
    serverSocket = nonBlockServerSocket;
    setEventByFD(nonBlockServerSocket.fd, &serverSocket);
}

void KQueueMultiplexing::closeNonBlockSocket(const NonBlockSocket &nonBlockSocket) {
    nonBlockSocketsMap.erase(nonBlockSocket.fd);
    nonBlockSocket.closeSocket();
}

[[noreturn]] void KQueueMultiplexing::start() {
    for (;;) {
        int n = kevent(fd, NULL, 0, &events[0], 100, NULL);

        for (int i = 0; i < n; ++i) {
            if (events[i].flags & EVFILT_READ) {
                if (events[i].ident == serverSocket.fd) {
                    if (handleAccept != nullptr) {
                        handleAccept(*static_cast<NonBlockServerSocket*>(events[i].udata));
                    }
                } else {
                    if (handleRead != nullptr) {
                        NonBlockSocket* clientSocket = static_cast<NonBlockSocket*>(events[i].udata);
                        handleRead(*clientSocket);
                    }
                }
            }
        }
    }
}