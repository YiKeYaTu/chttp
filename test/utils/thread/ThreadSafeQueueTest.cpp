//
// Created by lc on 2021/12/28.
//

#include <gtest/gtest.h>
#include <thread>
#include <memory>
#include "utils/thread/ThreadSafeBlockingQueue.h"

TEST(ThreadSafeQueue, ThreadSafeQueueTest) {
    ThreadSafeBlockingQueue<int> threadSafeBlockingQueue(4);

    std::vector<std::shared_ptr<std::thread>> consumers;
    std::vector<std::shared_ptr<std::thread>> producers;

    for (int i = 0; i < 100; ++i) {
        std::thread* p = new std::thread([&threadSafeBlockingQueue]() {
            std::cout << "pop: " << threadSafeBlockingQueue.waitAndPop() << std::endl;
        });
        consumers.push_back(std::shared_ptr<std::thread>(p));
    }

    for (int i = 0; i < 100; ++i) {
        std::thread* p = new std::thread([&threadSafeBlockingQueue, i]() {
            threadSafeBlockingQueue.waitAndPush(i);
        });
        consumers.push_back(std::shared_ptr<std::thread>(p));
    }

    std::for_each(consumers.begin(), consumers.end(), [](std::shared_ptr<std::thread>& ptr) {
        ptr->join();
    });
    std::for_each(producers.begin(), producers.end(), [](std::shared_ptr<std::thread>& ptr) {
        ptr->join();
    });


    ASSERT_EQ(threadSafeBlockingQueue.size(), 0);
}

