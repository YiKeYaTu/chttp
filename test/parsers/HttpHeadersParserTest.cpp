//
// Created by lc on 2021/12/14.
//

#include <gtest/gtest.h>
#include <string>
#include "parsers/HttpHeadersParser.h"

TEST(HttpHeadersParser, TestSingleHttpHeader) {
    std::string header = "Accept: */*\r\n\r\n";
    HttpHeadersParser httpHeadersParser;
    std::optional<HttpHeaders> httpHeaders;

    for (const char& c: header) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), true);
    ASSERT_EQ(httpHeaders.has_value(), true);
    ASSERT_EQ(httpHeaders.value().getHeader("Accept"), "*/*");
}

TEST(HttpHeadersParser, TestMultipleHttpHeaders) {
    std::string headers = "Accept: */*\r\nContent-Length: 12\r\nContent-Type: text/plain\r\n\r\n";
    HttpHeadersParser httpHeadersParser;
    std::optional<HttpHeaders> httpHeaders;

    for (const char& c: headers) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), true);
    ASSERT_EQ(httpHeaders.has_value(), true);
    ASSERT_EQ(httpHeaders.value().getHeader("Accept"), "*/*");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Length"), "12");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Type"), "text/plain");
}

TEST(HttpHeadersParser, TestReset) {
    std::string headers = "Accept: */*\r\nContent-Length: 12\r\nContent-Type: text/plain\r\n\r\n";
    HttpHeadersParser httpHeadersParser;
    std::optional<HttpHeaders> httpHeaders;

    for (const char& c: headers) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), true);
    ASSERT_EQ(httpHeaders.has_value(), true);
    ASSERT_EQ(httpHeaders.value().getHeader("Accept"), "*/*");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Length"), "12");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Type"), "text/plain");

    std::string header = "Accept: */*\r\n\r\n";

    httpHeadersParser.reset();
    for (const char& c: header) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), true);
    ASSERT_EQ(httpHeaders.has_value(), true);
    ASSERT_EQ(httpHeaders.value().getHeader("Accept"), "*/*");
}

TEST(HttpHeadersParser, TestUnendingHeaders) {
    std::string headers = "Accept: */*\r\nContent-Length: 12\r\nContent-Type: text/plain\r\n";
    HttpHeadersParser httpHeadersParser;
    std::optional<HttpHeaders> httpHeaders;

    for (const char &c: headers) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), false);
    ASSERT_EQ(httpHeaders.has_value(), false);
}


TEST(HttpHeadersParser, TestContinuedHeaders) {
    std::string headers = "Accept: */*\r\nContent-Length: 12\r\nContent-Type: text/plain\r\n";
    HttpHeadersParser httpHeadersParser;
    std::optional<HttpHeaders> httpHeaders;

    for (const char &c: headers) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), false);
    ASSERT_EQ(httpHeaders.has_value(), false);

    std::string CRLF = "\r\n";

    for (const char &c: CRLF) {
        httpHeaders = httpHeadersParser.parse(&c);
    }

    ASSERT_EQ(httpHeadersParser.isCompleted(), true);
    ASSERT_EQ(httpHeaders.has_value(), true);
    ASSERT_EQ(httpHeaders.value().getHeader("Accept"), "*/*");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Length"), "12");
    ASSERT_EQ(httpHeaders.value().getHeader("Content-Type"), "text/plain");
}