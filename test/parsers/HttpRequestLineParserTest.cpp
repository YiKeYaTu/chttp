//
// Created by lc on 2021/12/16.
//

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <optional>
#include "http/HttpRequestLine.h"
#include "parsers/HttpRequestLineParser.h"

TEST(HttpRequestLineParser, TestOneRequestLine) {
    std::string requestLine = "GET / HTTP/1.1\r\n";
    HttpRequestLineParser httpRequestLineParser;
    std::optional<HttpRequestLine> httpRequestLine;

    int count = 0;

    for (const char& c : requestLine) {
        httpRequestLine = httpRequestLineParser.parse(&c);
        if (count ++ != requestLine.size() - 1) {
            ASSERT_EQ(httpRequestLine.has_value(), false);
            ASSERT_EQ(httpRequestLineParser.isCompleted(), false);
        }
    }

    ASSERT_EQ(httpRequestLine.has_value(), true);
    ASSERT_EQ(httpRequestLineParser.isCompleted(), true);
    ASSERT_EQ(httpRequestLine.value().toString(), "GET / HTTP/1.1");
    ASSERT_EQ(httpRequestLine.value().getHttpMethod(), HttpMethod::HttpMethodEnum::GET);
    ASSERT_EQ(httpRequestLine.value().getUri().getUriString(), "/");
    ASSERT_EQ(httpRequestLine.value().getHttpVersion(), HttpVersion::HttpVersionEnum::HTTP_1_1);
}

TEST(HttpRequestLineParser, TestInvalidRequestLine) {
    std::string requestLine = "GET / HT P/1.1\r\n";
    HttpRequestLineParser httpRequestLineParser;
    std::optional<HttpRequestLine> httpRequestLine;

    EXPECT_THROW({
         for (const char& c : requestLine) {
             httpRequestLine = httpRequestLineParser.parse(&c);
         }
    }, std::invalid_argument);

    requestLine = "G ET / HTP/1.1\r\n";
    httpRequestLineParser.reset();
    ASSERT_EQ(httpRequestLineParser.isCompleted(), false);

    EXPECT_THROW({
        for (const char& c : requestLine) {
            httpRequestLine = httpRequestLineParser.parse(&c);
        }
    }, std::invalid_argument);
    ASSERT_EQ(httpRequestLineParser.isCompleted(), true);
}
