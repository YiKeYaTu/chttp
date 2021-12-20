//
// Created by lc on 2021/12/15.
//

#include <algorithm>
#include "http/HttpMethod.h"

const std::string HttpMethod::OPTIONS = "OPTIONS";
const std::string HttpMethod::GET = "GET";
const std::string HttpMethod::HEAD = "HEAD";
const std::string HttpMethod::POST = "POST";
const std::string HttpMethod::PUT = "PUT";
const std::string HttpMethod::DELETE = "DELETE";
const std::string HttpMethod::TRACE = "TRACE";
const std::string HttpMethod::CONNECT = "CONNECT";

const bool HttpMethod::isOneOfValidHttpMethods(const std::string& string) {
    if (string == OPTIONS || string == GET     ||
        string == HEAD    || string == POST    ||
        string == PUT     || string == DELETE  ||
        string == TRACE   || string == CONNECT
    ) {
        return true;
    }
    return false;
}