//
// Created by lc on 2021/12/13.
//

#include "http/HttpHeaders.h"
#include <string>

HttpHeaders::HttpHeaders(std::map<std::string, std::string>& headersMap) {
    this->headersMap = headersMap;
}

void HttpHeaders::setHeader(std::string&& k, std::string&& v) {
    headersMap.insert_or_assign(k, v);
}

void HttpHeaders::setHeader(const std::string& k, const std::string& v) {
    headersMap.insert_or_assign(k, v);
}

void HttpHeaders::setHeaders(const HttpHeaders& httpHeaders) {
    const std::map<std::string, std::string>& tempHttpHeaders = httpHeaders.getHeaders();
    std::for_each(tempHttpHeaders.begin(), tempHttpHeaders.end(), [&](const std::pair<std::string, std::string>& p) {
        headersMap.insert_or_assign(p.first, p.second);
    });
}

const std::string& HttpHeaders::getHeader(const std::string& key) const {
    auto iterator = headersMap.find(key);
    if (iterator == headersMap.end()) {
        return "";
    }
    return iterator->second;
}

const bool HttpHeaders::hasHeader(const std::string& key) const {
    return headersMap.contains(key);
}