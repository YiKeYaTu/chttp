//
// Created by lc on 2021/12/21.
//

#include "NonBlockSocket.h"
#include <fcntl.h>
#include <unistd.h>

NonBlockSocket::NonBlockSocket(const ssize_t& fd, struct sockaddr_in& address)
: fd(fd), address(address) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
}

int NonBlockSocket::readFromSocket(std::shared_ptr<char[]> ptr, ssize_t size) const {
    return ::read(fd, ptr.get(), size);
}

int NonBlockSocket::writeToSocket(std::shared_ptr<char[]> ptr, ssize_t size) const {
    return ::write(fd, ptr.get(), size);
}

int NonBlockSocket::closeSocket() const {
    return ::close(fd);
}