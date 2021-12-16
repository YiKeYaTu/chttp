//
// Created by lc on 2021/12/15.
//

#ifndef CHTTP_HTTPREQUESTLINE_H
#define CHTTP_HTTPREQUESTLINE_H

#include <string>
#include "HttpMethod.h"
#include "HttpVersion.h"
#include "URI.h"

class HttpRequestLine  {
public:
    HttpRequestLine(std::string& httpMethod, std::string& uri, std::string& httpVersion): httpMethod(HttpMethod::convertString2Enum(httpMethod)), uri(URI::create(uri)), httpVersion(HttpVersion::convertString2Enum(httpVersion)) {}

    inline HttpMethod::HttpMethodEnum getHttpMethod() const {
        return httpMethod;
    }

    inline const URI& getUri() const {
        return uri;
    }

    inline HttpVersion::HttpVersionEnum getHttpVersion() const {
        return httpVersion;
    }

    inline std::string toString() {
        return convertEnum2String(httpMethod) + " " + uri.getUriString() + " " + convertEnum2String(httpVersion);
    }

private:
    HttpMethod::HttpMethodEnum httpMethod;
    URI uri;
    HttpVersion::HttpVersionEnum httpVersion;
};


#endif //CHTTP_HTTPREQUESTLINE_H
