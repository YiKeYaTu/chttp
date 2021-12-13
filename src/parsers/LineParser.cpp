//
// Created by lc on 2021/12/12.
//

#include "parsers/LineParser.h"

const std::string LineParser::CRLFSeparators = "\r\n";

std::optional<std::string> LineParser::parseChar(const char* c) {
    int separatorIndex = lineSeparators.find(*c);

    if (separatorIndex == -1) {
        if (statusOfSeparatorIndex > 0) {
            throw std::invalid_argument("invalid sequence: '" + storedString + "', with unexpected char between separators");
        }
        storedString.append(1, *c);
    } else {
        if (separatorIndex == statusOfSeparatorIndex) {
            statusOfSeparatorIndex ++;
        } else {
            throw std::invalid_argument("invalid sequence: '" + storedString + "', with incorrect orders of separators");
        }

        if (statusOfSeparatorIndex == lineSeparators.length()) {
            return std::make_optional(storedString);
        }
    }

    return std::nullopt;
}

void LineParser::resetStatus() {
    statusOfSeparatorIndex = 0;
}