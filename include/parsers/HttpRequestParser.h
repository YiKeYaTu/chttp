//
// Created by lc on 2021/12/18.
//

#ifndef CHTTP_HTTPREQUESTPARSER_H
#define CHTTP_HTTPREQUESTPARSER_H

#include <memory>

#include "AbstractParser.h"
#include "HttpRequestLineParser.h"
#include "HttpHeadersParser.h"
#include "HttpMessageBodyParser.h"

#include "http/HttpRequest.h"
#include "http/HttpRequestLine.h"
#include "http/HttpHeaders.h"
#include "http/HttpMessageBody.h"

class HttpRequestParser : public AbstractParser<HttpRequest> {
protected:
    std::optional<HttpRequest> parseChar(const char *) override;
    void resetStatus() override;

private:
    HttpRequestLineParser httpRequestLineParser;
    HttpHeadersParser httpHeadersParser;
    std::shared_ptr<HttpMessageBodyParser> httpMessageBodyParser;

    std::shared_ptr<HttpRequestLine> httpRequestLine;
    std::shared_ptr<HttpHeaders> httpHeaders;
    std::shared_ptr<HttpMessageBody> httpMessageBody;
};


#endif //CHTTP_HTTPREQUESTPARSER_H
