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
    HttpRequestLine(std::string&, std::string&, std::string&);
    const std::string& getHttpMethod() const;
    const URI& getUri() const;
    const std::string& getHttpVersion() const;
private:
    std::string httpMethod;
    URI uri;
    std::string httpVersion;
};


#endif //CHTTP_HTTPREQUESTLINE_H
