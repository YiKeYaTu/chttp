//
// Created by lc on 2021/12/12.
//

#ifndef SUBPROJECTS_LINEPARSER_H
#define SUBPROJECTS_LINEPARSER_H

#include <string>
#include "parsers/AbstractParser.h"

class LineParser: public AbstractParser<std::string> {
public:
    static const std::string CRLFSeparators;
    LineParser(): lineSeparators(CRLFSeparators) {}
    LineParser(const std::string& lineSeparators): lineSeparators(lineSeparators) {}
    ~LineParser() = default;
protected:
    std::optional<std::string> parseChar(const char*) override;
    void resetStatus() override;
    const std::string lineSeparators;
    unsigned int statusOfSeparatorIndex = 0;
};


#endif //SUBPROJECTS_LINEPARSER_H
