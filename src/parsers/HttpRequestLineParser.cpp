//
// Created by lc on 2021/12/16.
//

#include <optional>
#include "parsers/HttpRequestLineParser.h"
#include "../utils/stringUtils.h"

std::optional<HttpRequestLine> HttpRequestLineParser::parseChar(const char* c) {
    std::optional<std::string> optLine = lineParser.parse(c);

    if (!optLine.has_value()) {
        return std::nullopt;
    }

    const std::string& line = optLine.value();
    StringSplittingIterator stringSplittingIterator(line, " ");

    std::string methodURIVersion[3];
    unsigned short index = 0;

    do {
        const std::string temp = *stringSplittingIterator;
        if (temp != "") {
            methodURIVersion[index ++] = temp;
        }
    } while (index < 3 && (stringSplittingIterator ++).hasNext());

    if (stringSplittingIterator.hasNext() || index < 3) {
        throw std::invalid_argument("Invalid http request line");
    }

    return std::make_optional(HttpRequestLine(methodURIVersion[0], methodURIVersion[1], methodURIVersion[2]));
}

void HttpRequestLineParser::resetStatus() {
    lineParser.reset();
}