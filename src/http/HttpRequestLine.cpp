//
// Created by lc on 2021/12/15.
//

#include "http/HttpRequestLine.h"

HttpRequestLine::HttpRequestLine(std::string& httpMethod, std::string& uri, std::string& httpVersion):
uri(URI::create(uri)) {
    if (HttpMethod::isOneOfValidHttpMethods(httpMethod)) {
        this->httpMethod = httpMethod;
    } else {
        throw std::invalid_argument("Invalid http method: " + httpMethod);
    }

    if (HttpVersion::isOneOfValidHttpVersions(httpVersion)) {
        this->httpVersion = httpVersion;
    } else {
        throw std::invalid_argument("Invalid http version: " + httpVersion);
    }
}

const std::string &HttpRequestLine::getHttpMethod() const {
    return httpMethod;
}

const URI &HttpRequestLine::getUri() const {
    return uri;
}

const std::string &HttpRequestLine::getHttpVersion() const {
    return httpVersion;
}
