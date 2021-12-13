//
// Created by lc on 2021/12/13.
//

#include "parsers/HttpHeaderParser.h"
#include "utils/stringUtils.h"
#include <vector>

std::optional<HttpHeaderParser::httpHeader> HttpHeaderParser::parseChar(const char* c) {
    std::optional<std::string> optLine = lineParser.parse(c);

    if (optLine.has_value()) {
        std::string line = optLine.value();

        int colonPos = line.find(":", 0);

        if (colonPos == -1) {
            throw std::invalid_argument("Invalid http header format: '" + line + "'");
        }

        std::string k = line.substr(0, colonPos);
        std::string v = line.substr(colonPos + 1);

        trim(k);
        trim(v);

        if (k.length() == 0 || v.length() == 0) {
            throw std::invalid_argument("Invalid http header format: '" + line + "'");
        }

        return std::make_optional(std::pair<std::string, std::string> (k, v));
    }

    return std::nullopt;
}

void HttpHeaderParser::resetStatus() {
    lineParser.reset();
}