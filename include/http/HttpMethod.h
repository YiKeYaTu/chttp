//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPMETHOD_H
#define CHTTP_HTTPMETHOD_H

#include <string>

namespace HttpMethod {
    extern std::string OPTIONS;
    extern std::string GET;
    extern std::string HEAD;
    extern std::string POST;
    extern std::string PUT;
    extern std::string DELETE;
    extern std::string TRACE;
    extern std::string CONNECT;

    bool isOneOfValidHttpMethods(const std::string&);
};

#endif //CHTTP_HTTPMETHOD_H
