//
// Created by lc on 2021/12/17.
//

#ifndef CHTTP_HTTPMESSAGEBODYPARSER_H
#define CHTTP_HTTPMESSAGEBODYPARSER_H

#include <iostream>
#include "http/HttpMessageBody.h"
#include "parsers/AbstractParser.h"
#include "parsers/FixedLengthLineParser.h"

class HttpMessageBodyParser : public AbstractParser<HttpMessageBody> {
public:
    static std::shared_ptr<HttpMessageBodyParser> getInstance(const std::size_t& contentLength);
    static std::shared_ptr<HttpMessageBodyParser> getInstance(const HttpHeaders& httpHeaders);

    virtual const bool hasBody() const = 0;
    virtual const bool hasExtraHttpHeaders() const = 0;
    virtual const HttpHeaders getExtraHttpHeaders() const = 0;
};

class FixedLengthBodyParser : public HttpMessageBodyParser {
public:
    FixedLengthBodyParser(const std::size_t& contentLength);
    const bool hasBody() const override { return true; };
    const bool hasExtraHttpHeaders() const override { return false; };
    const HttpHeaders getExtraHttpHeaders() const override {
        throw std::logic_error("can not call getExtraHttpHeaders() by instance of FixedLengthBodyParser");
    }
private:
    FixedLengthLineParser fixedLengthLineParser;
protected:
    std::optional<HttpMessageBody> parseChar(const char*) override;
    void resetStatus() override;
};


#endif //CHTTP_HTTPMESSAGEBODYPARSER_H
