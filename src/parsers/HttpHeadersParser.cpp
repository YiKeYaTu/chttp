//
// Created by lc on 2021/12/14.
//

#include "parsers/HttpHeadersParser.h"

std::optional<HttpHeaders> HttpHeadersParser::parseChar(const char* c) {
    std::optional<std::pair<std::string, std::string>> optHttpHeader = httpHeaderParser.parse(c);

    if (optHttpHeader.has_value()) {
        auto httpHeader = optHttpHeader.value();
        httpHeaderParser.reset();

        if (httpHeader.first.length() == 0) {
            return std::make_optional(httpHeaders);
        } else {
            httpHeaders.setHeader(httpHeader.first, httpHeader.second);
        }
    }

    return std::nullopt;
}

void HttpHeadersParser::resetStatus() {
    httpHeaderParser.reset();
}