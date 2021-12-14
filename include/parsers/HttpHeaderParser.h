//
// Created by lc on 2021/12/13.
//

#ifndef CHTTP_HEADERPARSER_H
#define CHTTP_HEADERPARSER_H

#include "AbstractParser.h"
#include "http/HttpHeaders.h"
#include "parsers/LineParser.h"

class HttpHeaderParser: public AbstractParser<std::pair<std::string, std::string>> {
public:
    typedef std::pair<std::string, std::string> httpHeader;
    virtual ~HttpHeaderParser() = default;
protected:
    LineParser lineParser;
    std::optional<httpHeader> parseChar(const char*) override;
    void resetStatus() override;
};


#endif //CHTTP_HEADERPARSER_H
