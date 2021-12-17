//
// Created by lc on 2021/12/17.
//

#ifndef CHTTP_HTTPMESSAGEBODY_H
#define CHTTP_HTTPMESSAGEBODY_H

#include <cstddef>
#include <vector>
#include "http/HttpHeaders.h"

class HttpMessageBody {
private:
    std::vector<std::byte> bodyBytes;
    HttpHeaders extraHttpHeaders;
};


#endif //CHTTP_HTTPMESSAGEBODY_H
