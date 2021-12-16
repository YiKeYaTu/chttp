//
// Created by lc on 2021/12/16.
//

#ifndef CHTTP_HTTPREQUESTLINEPARSER_H
#define CHTTP_HTTPREQUESTLINEPARSER_H

#include "parsers/AbstractParser.h"
#include "parsers/LineParser.h"
#include "http/HttpRequestLine.h"

class HttpRequestLineParser : public AbstractParser<HttpRequestLine> {
protected:
    std::optional<HttpRequestLine> parseChar(const char *) override;
    void resetStatus() override;
private:
    LineParser lineParser;
};


#endif //CHTTP_HTTPREQUESTLINEPARSER_H
