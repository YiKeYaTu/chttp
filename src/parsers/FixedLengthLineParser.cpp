//
// Created by lc on 2021/12/12.
//

#include "parsers/FixedLengthLineParser.h"

std::optional<std::string> FixedLengthLineParser::parseChar(const char* c) {
    if (storedString.length() == length) {
        if (lineSeparators.length() == 0) {
            return std::make_optional(storedString);
        }

        int currentSeparatorIndex = lineSeparators.find(*c);
        if (currentSeparatorIndex == statusOfSeparatorIndex) {
            statusOfSeparatorIndex ++;
        } else {
            throw std::invalid_argument("invalid sequence: '" + storedString + "', with unexpected chars after reaching target length");
        }

        if (statusOfSeparatorIndex == lineSeparators.length()) {
            return std::make_optional(storedString);
        }
    } else {
        storedString.append(1, *c);
    }

    return std::nullopt;
}