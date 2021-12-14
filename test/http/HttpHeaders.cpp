//
// Created by lc on 2021/12/14.
//

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "http/HttpHeaders.h"

char c = 'A';

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& hasPtr):
        ps(new std::string(*hasPtr.ps)), i(hasPtr.i){}
private:
    std::string* ps;
    int i;
};

void setHeaders(HttpHeaders& httpHeaders) {
    std::string k = "key", v = std::string(1, c ++);
    httpHeaders.setHeader(k, v);
}

TEST(HttpHeaders, TestCopyConstructor) {
    HttpHeaders httpHeaders1;
    setHeaders(httpHeaders1);

    HttpHeaders httpHeaders2 = httpHeaders1;
    setHeaders(httpHeaders2);

    httpHeaders2 = httpHeaders1;
    setHeaders(httpHeaders2);

    std::cout << httpHeaders1.getHeader("key") << std::endl;
    std::cout << httpHeaders2.getHeader("key") << std::endl;
}