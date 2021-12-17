//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPVERSION_H
#define CHTTP_HTTPVERSION_H

#include <string>

namespace HttpVersion {
    extern std::string HTTP_1_1;
    extern std::string HTTP_2;

    bool isOneOfValidHttpVersions(const std::string&);
};

#endif //CHTTP_HTTPVERSION_H
