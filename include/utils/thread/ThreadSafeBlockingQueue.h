//
// Created by lc on 2021/12/28.
//

#ifndef CHTTP_THREADSAFEBLOCKINGQUEUE_H
#define CHTTP_THREADSAFEBLOCKINGQUEUE_H

#include <queue>
#include <shared_mutex>
#include <limits>
#include <mutex>
#include <iostream>
#include <condition_variable>

//template<typename T>
//class ThreadSafeBlockingQueue {
//public:
//    ThreadSafeBlockingQueue() = delete;
//    ThreadSafeBlockingQueue(const std::size_t& cap)
//    : capacity(cap), container(alloc.allocate(cap + 1)) {}
//    ~ThreadSafeBlockingQueue() { alloc.deallocate(container, capacity + 1); }
//
//    void waitAndPush(const T&&);
//    T waitAndPop();
//    std::size_t size() const;
//private:
//    std::size_t front = 0;
//    std::size_t back = 0;
//
//    std::size_t capacity;
//
//    std::allocator<T> alloc;
//    T* container;
//
//    mutable std::shared_mutex frontMutex;
//    mutable std::shared_mutex backMutex;
//    std::condition_variable_any fullCond;
//    std::condition_variable_any emptyCond;
//
//    std::size_t _size() const;
//    std::size_t _empty() const;
//};
//
//template<typename T>
//std::size_t ThreadSafeBlockingQueue<T>::_size() const {
//    return (back + capacity + 1 - front) % (capacity + 1);
//}
//
//template<typename T>
//std::size_t ThreadSafeBlockingQueue<T>::_empty() const {
//    return front == back;
//}
//
//template<typename T>
//std::size_t ThreadSafeBlockingQueue<T>::size() const {
//    std::unique_lock frontUniqueLock(frontMutex, std::defer_lock);
//    std::unique_lock backUniqueLock(backMutex,  std::defer_lock);
//    std::lock(frontUniqueLock, backUniqueLock);
//    return _size();
//}
//
//template<typename T>
//void ThreadSafeBlockingQueue<T>::waitAndPush(const T&& value) {
//    std::unique_lock backUniqueLock(backMutex);
//    fullCond.wait(backUniqueLock, [&]() {
//        return _size() < capacity;
//    });
//
//    container[back] = value;
//    back = (back + 1) % (capacity + 1);
//
//    emptyCond.notify_one();
//}
//
//template<typename T>
//T ThreadSafeBlockingQueue<T>::waitAndPop() {
//    std::unique_lock frontUniqueLock(frontMutex);
//    emptyCond.wait(frontUniqueLock, [&]() {
//        return !_empty();
//    });
//
//    T ret = container[front];
//    front = (front + 1) % (capacity + 1);
//
//    fullCond.notify_one();
//
//    return ret;
//}

template<typename T>
class ThreadSafeBlockingQueue {
public:
    ThreadSafeBlockingQueue() = delete;
    ThreadSafeBlockingQueue(const std::size_t& cap)
            : capacity(cap), container(alloc.allocate(cap + 1)) {}
    ~ThreadSafeBlockingQueue() { alloc.deallocate(container, capacity + 1); }

    void waitAndPush(const T&);
    T waitAndPop();
    std::size_t size() const;
private:
    std::size_t front = 0;
    std::size_t back = 0;

    std::size_t capacity;

    std::allocator<T> alloc;
    T* container;

    mutable std::shared_mutex sharedMutex;
    std::condition_variable_any fullCond;
    std::condition_variable_any emptyCond;

    std::size_t _size() const;
    std::size_t _empty() const;
};

template<typename T>
std::size_t ThreadSafeBlockingQueue<T>::_size() const {
    return (back + capacity + 1 - front) % (capacity + 1);
}

template<typename T>
std::size_t ThreadSafeBlockingQueue<T>::_empty() const {
    return front == back;
}

template<typename T>
std::size_t ThreadSafeBlockingQueue<T>::size() const {
    std::shared_lock sharedUniqueLock(sharedMutex);
    return _size();
}

template<typename T>
void ThreadSafeBlockingQueue<T>::waitAndPush(const T& value) {
    std::unique_lock uniqueLock(sharedMutex);
    fullCond.wait(uniqueLock, [&]() {
        return _size() < capacity;
    });

    container[back] = value;
    back = (back + 1) % (capacity + 1);

    emptyCond.notify_one();
}

template<typename T>
T ThreadSafeBlockingQueue<T>::waitAndPop() {
    std::unique_lock uniqueLock(sharedMutex);
    emptyCond.wait(uniqueLock, [&]() {
        return !_empty();
    });

    T ret = container[front];
    front = (front + 1) % (capacity + 1);

    fullCond.notify_one();

    return ret;
}

#endif //CHTTP_THREADSAFEBLOCKINGQUEUE_H
