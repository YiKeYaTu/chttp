//
// Created by lc on 2021/12/17.
//

#include "parsers/HttpMessageBodyParser.h"

std::shared_ptr<HttpMessageBodyParser> HttpMessageBodyParser::getInstance(const HttpHeaders &httpHeaders) {}

std::shared_ptr<HttpMessageBodyParser> HttpMessageBodyParser::getInstance(const std::size_t &contentLength) {
    return std::make_shared<FixedLengthBodyParser>(FixedLengthBodyParser(contentLength));
}

std::optional<HttpMessageBody> FixedLengthBodyParser::parseChar(const char* c) {
    std::optional<std::string> string = fixedLengthLineParser.parse(c);

    if (!string.has_value()) {
        return std::nullopt;
    }

    return HttpMessageBody();
}

void FixedLengthBodyParser::resetStatus() {
    fixedLengthLineParser.reset();
}