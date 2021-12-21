//
// Created by lc on 2021/12/12.
//

#include <iostream>
#include <vector>
#include "core/NonBlockServerSocket.h"
#include "core/KQueueMultiplexing.h"

int main()
{

//    NonBlockServerSocket nonBlockServerSocket;
//    nonBlockServerSocket.bind(8000);
//    nonBlockServerSocket.listen();
//
//    KQueueMultiplexing kQueueMultiplexing;
//    kQueueMultiplexing.addNonBlockServerSocket(nonBlockServerSocket);
//    kQueueMultiplexing.onAccept([&kQueueMultiplexing](NonBlockServerSocket& nonBlockServerSocket) {
//        NonBlockSocket nonBlockSocket = nonBlockServerSocket.accept();
//        kQueueMultiplexing.addNonBlockSocket(nonBlockSocket);
//    });
//    kQueueMultiplexing.onRead([](NonBlockSocket& nonBlockSocket) {
//        std::shared_ptr<char[]> buffer(new char[1024]);
//        std::cout << "start reading" << std::endl;
//        int n = nonBlockSocket.readFromSocket((buffer), 1024);
//        std::cout << "read count: " << n << std::endl;
//        std::cout << "end reading" << std::endl;
//        if (n == 0) {
//            nonBlockSocket.close();
//        } else {
//            std::cout << buffer << std::endl;
//        }
//    });
//    std::cout << "start listening" << std::endl;
//    kQueueMultiplexing.start();
    return 0;
}