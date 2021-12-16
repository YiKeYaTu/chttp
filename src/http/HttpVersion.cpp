//
// Created by lc on 2021/12/16.
//

#include "http/HttpVersion.h"

HttpVersion::HttpVersionEnum HttpVersion::convertString2Enum(const std::string& string) {
    if (string == "HTTP/1.1") {
        return HttpVersionEnum::HTTP_1_1;
    } else if (string == "HTTP/2") {
        return HttpVersionEnum::HTTP_2;
    }
    throw std::invalid_argument("Invalid string of http version: " + string);
}

HttpVersion::HttpVersionEnum HttpVersion::convertString2Enum(std::string&& string) {
    return convertString2Enum(std::move(string));
}

std::string HttpVersion::convertEnum2String(const HttpVersionEnum& httpVersionEnum) {
    switch (httpVersionEnum) {
        case HttpVersionEnum::HTTP_1_1:
            return "HTTP/1.1";
        case HttpVersionEnum::HTTP_2:
            return "HTTP/2";
        default:
            throw std::invalid_argument("Invalid enum of http version");
    }
}