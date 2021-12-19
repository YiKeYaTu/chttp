//
// Created by lc on 2021/12/12.
//

#include "parsers/FixedLengthLineParser.h"

std::optional<std::string> FixedLengthLineParser::parseChar(const char* c) {
    if (statusOfSeparatorIndex > 0 || storedString.length() == length) {
        int currentSeparatorIndex = lineSeparators.find(*c);
        if (currentSeparatorIndex == statusOfSeparatorIndex) {
            statusOfSeparatorIndex ++;
        } else {
            throw std::invalid_argument("invalid sequence: '" + storedString + "', with unexpected chars after reaching target length");
        }
    } else {
        storedString.append(1, *c);
    }

    if (storedString.length() != length) {
        return std::nullopt;
    }

    if (lineSeparators.length() == 0 || statusOfSeparatorIndex == lineSeparators.length()) {
        return std::make_optional(storedString);
    }

    return std::nullopt;
}