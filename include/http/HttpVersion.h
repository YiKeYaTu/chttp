//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPVERSION_H
#define CHTTP_HTTPVERSION_H

#include <string>

namespace HttpVersion {
    enum class HttpVersionEnum {
        HTTP_1_1,
        HTTP_2
    };

    std::string convertEnum2String(const HttpVersionEnum&);
    HttpVersionEnum convertString2Enum(std::string &&);
    HttpVersionEnum convertString2Enum(const std::string &);
};

#endif //CHTTP_HTTPVERSION_H
