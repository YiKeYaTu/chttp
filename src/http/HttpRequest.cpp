//
// Created by lc on 2021/12/18.
//

#include "http/HttpRequest.h"

HttpRequest::HttpRequest(const HttpRequestLine &httpRequestLine, const HttpHeaders &httpHeaders,
                         const HttpMessageBody &httpMessageBody) : httpRequestLine(httpRequestLine),
                                                                   httpHeaders(httpHeaders),
                                                                   httpMessageBody(httpMessageBody) {}

const HttpRequestLine &HttpRequest::getHttpRequestLine() const {
    return httpRequestLine;
}

const HttpHeaders &HttpRequest::getHttpHeaders() const {
    return httpHeaders;
}

const HttpMessageBody &HttpRequest::getHttpMessageBody() const {
    return httpMessageBody;
}
