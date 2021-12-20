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
};

class FixedLengthBodyParser : public HttpMessageBodyParser {
public:
    FixedLengthBodyParser(const std::size_t& contentLength);
    const bool hasBody() const override { return true; };
private:
    FixedLengthLineParser fixedLengthLineParser;
protected:
    std::optional<HttpMessageBody> parseChar(const char*) override;
    void resetStatus() override;
};

class EmptyBodyParser : public HttpMessageBodyParser {
public:
    const bool hasBody() const override { return false; }

protected:
    std::optional<HttpMessageBody> parseChar(const char*) override {
        throw std::logic_error("can not call parseChar() by instance of EmptyBodyParser");
    }
    void resetStatus() override {
        throw std::logic_error("can not call parseChar() by instance of EmptyBodyParser");
    }
};


#endif //CHTTP_HTTPMESSAGEBODYPARSER_H
