//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPMETHOD_H
#define CHTTP_HTTPMETHOD_H

#include <string>

namespace HttpMethod {
    extern const std::string OPTIONS;
    extern const std::string GET;
    extern const std::string HEAD;
    extern const std::string POST;
    extern const std::string PUT;
    extern const std::string DELETE;
    extern const std::string TRACE;
    extern const std::string CONNECT;

    const bool isOneOfValidHttpMethods(const std::string&);
};

#endif //CHTTP_HTTPMETHOD_H
