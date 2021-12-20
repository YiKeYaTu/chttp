//
// Created by lc on 2021/12/17.
//

#include "parsers/HttpMessageBodyParser.h"
#include <iostream>

std::shared_ptr<HttpMessageBodyParser> HttpMessageBodyParser::getInstance(const HttpHeaders &httpHeaders) {
    const std::string& contentLength = httpHeaders.getHeader("Content-Length");
    const std::string& transferCoding = httpHeaders.getHeader("Transfer-Coding");

    if (httpHeaders.hasHeader("Transfer-Coding")) {

    } else if (httpHeaders.hasHeader("Content-Length")) {
        return std::shared_ptr<FixedLengthBodyParser> (new FixedLengthBodyParser(std::stoi(contentLength)));
    } else {
        return std::shared_ptr<EmptyBodyParser>(new EmptyBodyParser());
    }
}

std::shared_ptr<HttpMessageBodyParser> HttpMessageBodyParser::getInstance(const std::size_t &contentLength) {
    return std::shared_ptr<FixedLengthBodyParser>(new FixedLengthBodyParser(contentLength));
}

FixedLengthBodyParser::FixedLengthBodyParser(const std::size_t &contentLength):
fixedLengthLineParser(contentLength, "") {}

std::optional<HttpMessageBody> FixedLengthBodyParser::parseChar(const char* c) {
    std::optional<std::string> string = fixedLengthLineParser.parse(c);

    if (!string.has_value()) {
        return std::nullopt;
    }

    return HttpMessageBody(string.value());
}

void FixedLengthBodyParser::resetStatus() {
    fixedLengthLineParser.reset();
}