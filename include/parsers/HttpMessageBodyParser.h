//
// Created by lc on 2021/12/17.
//

#ifndef CHTTP_HTTPMESSAGEBODYPARSER_H
#define CHTTP_HTTPMESSAGEBODYPARSER_H

#include "http/HttpMessageBody.h"
#include "parsers/AbstractParser.h"
#include "parsers/FixedLengthLineParser.h"

class HttpMessageBodyParser : public AbstractParser<HttpMessageBody> {
public:
    static std::shared_ptr<HttpMessageBodyParser> getInstance(const std::size_t& contentLength);
    static std::shared_ptr<HttpMessageBodyParser> getInstance(const HttpHeaders& httpHeaders);
};

class FixedLengthBodyParser : public HttpMessageBodyParser {
public:
    FixedLengthBodyParser() = default;
    FixedLengthBodyParser(const std::size_t& contentLength): fixedLengthLineParser(contentLength, "") {}
private:
    FixedLengthLineParser fixedLengthLineParser;
protected:
    std::optional<HttpMessageBody> parseChar(const char*) override;
    void resetStatus() override;
};


#endif //CHTTP_HTTPMESSAGEBODYPARSER_H
