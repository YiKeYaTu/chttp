//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPMETHOD_H
#define CHTTP_HTTPMETHOD_H

#include <string>

namespace HttpMethod {
    enum class HttpMethodEnum {
        OPTIONS,
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        TRACE,
        CONNECT
    };
    std::string convertEnum2String(const HttpMethodEnum&);
    HttpMethodEnum convertString2Enum(std::string &&);
    HttpMethodEnum convertString2Enum(const std::string &);
};

#endif //CHTTP_HTTPMETHOD_H
