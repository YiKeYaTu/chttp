//
// Created by lc on 2021/12/20.
//

#include <gtest/gtest.h>
#include "core/KQueueMultiplexing.h"
#include "core/NonBlockServerSocket.h"
#include <stack>

TEST(KQueueMultiplexing, TestHttpServerSocket) {
    NonBlockServerSocket nonBlockServerSocket;
    nonBlockServerSocket.bind(8000);
    nonBlockServerSocket.listen();

    KQueueMultiplexing kQueueMultiplexing;
    kQueueMultiplexing.addNonBlockServerSocket(nonBlockServerSocket);
    kQueueMultiplexing.onAccept([&kQueueMultiplexing](NonBlockServerSocket& nonBlockServerSocket) {
        kQueueMultiplexing.addNonBlockSocket(nonBlockServerSocket.accept());
    });
    kQueueMultiplexing.onRead([](NonBlockSocket& nonBlockSocket) {
        std::shared_ptr<char[]> buffer(new char[1024]);
        int n = nonBlockSocket.readFromSocket((buffer), 1024);

        if (n == 0) {
            nonBlockSocket.close();
        } else {
            std::cout << buffer << std::endl;
        }
    });
    kQueueMultiplexing.start();
}