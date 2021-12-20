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
    ASSERT_EQ(httpRequestParser.isCompleted(), false);

    for (const char& c : string1) {
        optHttpRequest = httpRequestParser.parse(&c);
    }

    ASSERT_EQ(httpRequestParser.isCompleted(), true);
    ASSERT_EQ(optHttpRequest.has_value(), true);
    ASSERT_EQ(optHttpRequest.value().getHttpRequestLine().getHttpVersion(), HttpVersion::HTTP_1_1);
    ASSERT_EQ(optHttpRequest.value().getHttpRequestLine().getUri().getUriString(), "/");
    ASSERT_EQ(optHttpRequest.value().getHttpRequestLine().getHttpMethod(), "GET");
    ASSERT_EQ(optHttpRequest.value().getHttpHeaders().getHeader("Accept"), "*/*");
    ASSERT_EQ(optHttpRequest.value().getHttpHeaders().size(), 1);
    ASSERT_EQ(optHttpRequest.value().getHttpMessageBody().isEmpty(), true);
}
