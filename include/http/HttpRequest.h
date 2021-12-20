//
// Created by lc on 2021/12/18.
//

#ifndef CHTTP_HTTPREQUEST_H
#define CHTTP_HTTPREQUEST_H

#include "http/HttpRequestLine.h"
#include "http/HttpHeaders.h"
#include "http/HttpMessageBody.h"

class HttpRequest {
private:
    HttpRequestLine httpRequestLine;
    HttpHeaders httpHeaders;
    HttpMessageBody httpMessageBody;
public:
    HttpRequest(const HttpRequestLine& httpRequestLine, const HttpHeaders& httpHeaders,
                const HttpMessageBody& httpMessageBody);

    const HttpRequestLine &getHttpRequestLine() const;

    const HttpHeaders &getHttpHeaders() const;

    const HttpMessageBody &getHttpMessageBody() const;
};


#endif //CHTTP_HTTPREQUEST_H
