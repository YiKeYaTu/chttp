//
// Created by lc on 2021/12/15.
//

#include <algorithm>
#include "http/HttpMethod.h"

HttpMethod::HttpMethodEnum HttpMethod::convertString2Enum(std::string&& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](char c) {
        return std::toupper(c);
    });

    if (str == "OPTIONS") {
        return HttpMethodEnum::OPTIONS;
    } else if (str == "GET") {
        return HttpMethodEnum::GET;
    } else if (str == "HEAD") {
        return HttpMethodEnum::HEAD;
    } else if (str == "POST") {
        return HttpMethodEnum::POST;
    } else if (str == "PUT") {
        return HttpMethodEnum::PUT;
    } else if (str == "DELETE") {
        return HttpMethodEnum::DELETE;
    } else if (str == "TRACE") {
        return HttpMethodEnum::TRACE;
    } else if (str == "CONNECT") {
        return HttpMethodEnum::CONNECT;
    }

    throw std::invalid_argument(std::string("Unacquainted http method: ") + str);
}
HttpMethod::HttpMethodEnum HttpMethod::convertString2Enum(const std::string& str) {
    std::string newStr = str;
    return convertString2Enum(std::move(newStr));
}
std::string HttpMethod::convertEnum2String(const HttpMethod::HttpMethodEnum& httpMethodEnum) {
    switch (httpMethodEnum) {
        case HttpMethodEnum::OPTIONS:
            return "OPTIONS";
        case HttpMethodEnum::GET:
            return "GET";
        case HttpMethodEnum::HEAD:
            return "HEAD";
        case HttpMethodEnum::POST:
            return "POST";
        case HttpMethodEnum::PUT:
            return "PUT";
        case HttpMethodEnum::DELETE:
            return "DELETE";
        case HttpMethodEnum::TRACE:
            return "TRACE";
        case HttpMethodEnum::CONNECT:
            return "CONNECT";
        default:
            throw std::invalid_argument("Invalid enum of http method");
    }
}
