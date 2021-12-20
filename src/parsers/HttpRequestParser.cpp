//
// Created by lc on 2021/12/18.
//

#include "parsers/HttpRequestParser.h"

std::optional<HttpRequest> HttpRequestParser::parseChar(const char* c) {
    if (httpRequestLine == nullptr) {
        std::optional<HttpRequestLine> optHttpRequestLine = httpRequestLineParser.parse(c);

        if (optHttpRequestLine.has_value()) {
            this->httpRequestLine = std::make_shared<HttpRequestLine>(optHttpRequestLine.value());
        }

        return std::nullopt;
    }

    if (httpHeaders == nullptr) {
        std::optional<HttpHeaders> optHttpHeaders = httpHeadersParser.parse(c);
        if (!optHttpHeaders.has_value()) {
            return std::nullopt;
        }

        httpHeaders = std::make_shared<HttpHeaders>(std::move(optHttpHeaders.value()));
        httpMessageBodyParser = HttpMessageBodyParser::getInstance(*httpHeaders);

        if (httpMessageBodyParser->hasBody()) {
            return std::nullopt;
        } else {
            return std::make_optional(HttpRequest(*httpRequestLine, *httpHeaders, HttpMessageBody()));
        }
    }

    if (httpMessageBody == nullptr) {
        std::optional<HttpMessageBody> optHttpMessageBody = httpMessageBodyParser->parse(c);
        if (!optHttpMessageBody.has_value()) {
            return std::nullopt;
        }

        HttpMessageBody& httpMessageBody = optHttpMessageBody.value();

        if (httpMessageBody.hasExtraHttpHeaders()) {
            httpHeaders->setHeaders(httpMessageBody.getExtraHttpHeaders());
        }

        return std::make_optional(HttpRequest(
                *httpRequestLine,
                *httpHeaders,
                httpMessageBody
        ));
    }
}

void HttpRequestParser::resetStatus() {
    httpRequestLineParser.reset();
    httpHeadersParser.reset();
    httpMessageBodyParser.reset();

    httpRequestLine.reset();
    httpHeaders.reset();
    httpMessageBody.reset();
}