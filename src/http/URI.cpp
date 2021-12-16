//
// Created by lc on 2021/12/16.
//

#include "http/URI.h"

URI URI::create(const std::string& uri) {
    return URI(uri);
}
URI::URI(const std::string& uri): uriString(uri) {}

const std::string &URI::getUriString() const {
    return uriString;
}
