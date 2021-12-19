//
// Created by lc on 2021/12/17.
//

#include <algorithm>
#include "http/HttpMessageBody.h"

HttpMessageBody::HttpMessageBody(const std::string& str): HttpMessageBody(str, HttpHeaders()) {}

HttpMessageBody::HttpMessageBody(const std::string& str, const HttpHeaders& extraHttpHeaders):
    extraHttpHeaders(extraHttpHeaders) {
    for (const char& c : str) {
        bodyBytes.push_back(static_cast<const std::byte>(c));
    }
}

const std::string HttpMessageBody::getMessageBodyWithString() const {
    std::string messageBodyString;
    std::for_each(bodyBytes.begin(), bodyBytes.end(), [&messageBodyString](const std::byte& b) {
        messageBodyString.push_back(static_cast<char>(b));
    });

    return messageBodyString;
}

const HttpHeaders &HttpMessageBody::getExtraHttpHeaders() const {
    return extraHttpHeaders;
}