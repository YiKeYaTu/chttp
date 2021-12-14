//
// Created by lc on 2021/12/12.
//

#include "parsers/LineParser.h"
#include "parsers/FixedLengthLineParser.h"
#include <iostream>
#include <memory>

template <class T>
class ShardPtr {
private:
    T* p;
    long* refCount;
public:
    ShardPtr(): refCount(new long(0)) {}
    ShardPtr(T* val): p(val), refCount(new long(1)) {}
    ShardPtr(const ShardPtr& shardPtr) {
        p = shardPtr.p;
        refCount = shardPtr.refCount;
        (*refCount) ++;
    }
    ~ShardPtr() {
        std::cout << "decrease refCount: " << *refCount - 1 << std::endl;
        if (-- (*refCount) <= 0) {
            delete refCount;

            if (*refCount == 0) {
                delete p;
            }
        }
    }

    ShardPtr<T>& operator=(const ShardPtr<T>& rightValue) {
        if (this == &rightValue) {
            return *this;
        }

        std::cout << "decrease left value's refCount: " << *refCount - 1 << std::endl;
        if (-- (*refCount) <= 0) {
            delete refCount;

            if (*refCount == 0) {
                delete p;
            }
        }

        p = rightValue.p;
        refCount = rightValue.refCount;

        (*refCount) ++;

        return *this;
    }

    T& operator*() {
        return getValue();
    }

    T& getValue() {
        return *p;
    }

    bool hasValue() {
        return p == nullptr;
    }
};

int main()
{

    int* data = new int (100);

    ShardPtr<int> pm1(data);
    ShardPtr<int> pm2(pm1);
    ShardPtr<int> pm3 = new int(121);

    pm3 = pm2;

    std::cout << *pm1 << std::endl;
    std::cout << *pm2 << std::endl;
    std::cout << *pm3 << std::endl;
    return 0;
}