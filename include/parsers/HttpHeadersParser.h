//
// Created by lc on 2021/12/14.
//

#ifndef CHTTP_HTTPHEADERSPARSER_H
#define CHTTP_HTTPHEADERSPARSER_H

#include "parsers/AbstractParser.h"
#include "parsers/HttpHeaderParserTest.h"
#include "http/HttpHeaders.h"

class HttpHeadersParser : public AbstractParser<HttpHeaders> {
private:
    HttpHeaderParserTest httpHeaderParser;
    HttpHeaders httpHeaders;
protected:
    std::optional<HttpHeaders> parseChar(const char *) override;
    void resetStatus() override;
public:
    virtual ~HttpHeadersParser() = default;
};


#endif //CHTTP_HTTPHEADERSPARSER_H
