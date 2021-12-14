//
// Created by lc on 2021/12/14.
//

#ifndef CHTTP_HTTPHEADERSPARSER_H
#define CHTTP_HTTPHEADERSPARSER_H

#include "parsers/AbstractParser.h"
#include "http/HttpHeaders.h"

class HttpHeadersParser : public AbstractParser<HttpHeaders> {
public:
    virtual ~HttpHeadersParser() = default;
};


#endif //CHTTP_HTTPHEADERSPARSER_H
