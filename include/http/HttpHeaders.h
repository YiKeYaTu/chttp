//
// Created by lc on 2021/12/13.
//

#ifndef CHTTP_HTTPHEADERS_H
#define CHTTP_HTTPHEADERS_H

#include <map>

class HttpHeaders {
private:
    std::map<std::string, std::string> headersMap;
public:
    void setHeader(std::pair<std::string, std::string>);
    void setHeader(std::string&, std::string&);

    HttpHeaders() = default;
    HttpHeaders(std::map<std::string, std::string>);
    HttpHeaders(HttpHeaders&);
};


#endif //CHTTP_HTTPHEADERS_H
