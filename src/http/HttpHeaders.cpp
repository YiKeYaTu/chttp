//
// Created by lc on 2021/12/13.
//

#include "http/HttpHeaders.h"
#include <string>

HttpHeaders::HttpHeaders(std::map<std::string, std::string>& headersMap) {
    this->headersMap = headersMap;
}

void HttpHeaders::setHeader(std::string& k, std::string& v) {
    headersMap.insert_or_assign(k, v);
}

const std::string& HttpHeaders::getHeader(const std::string& key) const {
    return headersMap.find(key)->second;
}