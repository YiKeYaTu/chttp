//
// Created by lc on 2021/12/17.
//

#ifndef CHTTP_HTTPMESSAGEBODY_H
#define CHTTP_HTTPMESSAGEBODY_H

#include <cstddef>
#include <vector>
#include <string>
#include "http/HttpHeaders.h"

class HttpMessageBody {
public:
    HttpMessageBody(const std::string&);
    HttpMessageBody(const std::string&, const HttpHeaders& extraHttpHeaders);
    HttpMessageBody() = default;

    const bool hasExtraHttpHeaders() const {
        return extraHttpHeaders.size() != 0;
    }
    const bool isEmpty() const {
        return bodyBytes.size() == 0;
    };
    const std::string getMessageBodyWithString() const;
    const HttpHeaders& getExtraHttpHeaders() const;
private:
    std::vector<std::byte> bodyBytes;
    HttpHeaders extraHttpHeaders;
};


#endif //CHTTP_HTTPMESSAGEBODY_H
