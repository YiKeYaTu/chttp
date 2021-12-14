//
// Created by lc on 2021/12/12.
//

#ifndef CHTTP_FIXEDLENGTHLINEPARSER_H
#define CHTTP_FIXEDLENGTHLINEPARSER_H

#include "parsers/LineParser.h"

class FixedLengthLineParser: public LineParser {
public:
    FixedLengthLineParser(unsigned long length):
        length(length) {}
    FixedLengthLineParser(unsigned long length, const char* const lineSeparators):
            length(length), LineParser(lineSeparators) {}
    virtual ~FixedLengthLineParser() = default;
protected:
    std::optional<std::string> parseChar(const char*) override;
private:
    const unsigned long length;
};


#endif //CHTTP_FIXEDLENGTHLINEPARSER_H
