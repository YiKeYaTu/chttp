//
// Created by lc on 2021/12/18.
//

#include <gtest/gtest.h>
#include <iostream>
#include "parsers/HttpRequestParser.h"

TEST(HttpRequestParser, TestGetRequest) {
    HttpRequestParser httpRequestParser;
    std::string string1 = "GET / HTTP/1.1\r\nAccept: */*\r\n\r\n";
    std::optional<HttpRequest> optHttpRequest;

    for (const char& c : string1) {
        optHttpRequest = httpRequestParser.parse(&c);
    }

    ASSERT_EQ(optHttpRequest.has_value(), true);
}
