//
// Created by lc on 2021/12/12.
//

#include "parsers/LineParser.h"
#include "parsers/FixedLengthLineParser.h"
#include <iostream>
#include <memory>

int& func1()
{
    int i;
    i = 1;
    return i;
}


int main() {
    int& p = func1();
    int c = func1();
    std::cout << p << std::endl;
    std::cout << c << std::endl;
    return 0;
}