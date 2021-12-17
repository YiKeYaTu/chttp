//
// Created by lc on 2021/12/16.
//

#include "http/HttpVersion.h"

std::string HttpVersion::HTTP_1_1 = "HTTP/1.1";
std::string HttpVersion::HTTP_2 = "HTTP/2";

bool HttpVersion::isOneOfValidHttpVersions(const std::string& string) {
    if (string == HTTP_1_1 || string == HTTP_2) {
        return true;
    }
    return false;
}