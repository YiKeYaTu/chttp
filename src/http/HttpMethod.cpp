//
// Created by lc on 2021/12/15.
//

#include <algorithm>
#include "http/HttpMethod.h"

std::string HttpMethod::OPTIONS = "OPTIONS";
std::string HttpMethod::GET = "GET";
std::string HttpMethod::HEAD = "HEAD";
std::string HttpMethod::POST = "POST";
std::string HttpMethod::PUT = "PUT";
std::string HttpMethod::DELETE = "DELETE";
std::string HttpMethod::TRACE = "TRACE";
std::string HttpMethod::CONNECT = "CONNECT";

bool HttpMethod::isOneOfValidHttpMethods(const std::string& string) {
    if (string == OPTIONS || string == GET     ||
        string == HEAD    || string == POST    ||
        string == PUT     || string == DELETE  ||
        string == TRACE   || string == CONNECT
    ) {
        return true;
    }
    return false;
}