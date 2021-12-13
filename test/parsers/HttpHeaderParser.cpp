//
// Created by lc on 2021/12/13.
//

#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include <iostream>
#include "parsers/HttpHeaderParser.h"

TEST(HttpHeaderParser, TestOneHttpHeader) {
    std::string s = "Content-Type: text/plain\r\n";
    HttpHeaderParser httpHeaderParser;
    std::optional<std::pair<std::string, std::string>> header;

    for (const char& c: s) {
        header = httpHeaderParser.parse(&c);

        if (header.has_value()) {
            EXPECT_EQ(header.value().first, "Content-Type");
            EXPECT_EQ(header.value().second, "text/plain");
            EXPECT_EQ(httpHeaderParser.isCompleted(), true);
        } else {
            EXPECT_EQ(httpHeaderParser.isCompleted(), false);
        }
    }
}

TEST(HttpHeaderParser, TestMultipleHttpHeaders) {
    std::string s = "Content-Type: text/plain\r\nAccept: */*\r\n";
    std::vector<std::pair<std::string, std::string>> pairs(
            {std::pair<std::string, std::string>("Content-Type", "text/plain"),
                    std::pair<std::string, std::string>("Accept", "*/*")
                            });
    HttpHeaderParser httpHeaderParser;
    std::optional<std::pair<std::string, std::string>> header;

    int counter = 0;

    for (const char& c: s) {
        header = httpHeaderParser.parse(&c);

        if (header.has_value()) {
            EXPECT_EQ(httpHeaderParser.isCompleted(), true);
            httpHeaderParser.reset();

            EXPECT_EQ(httpHeaderParser.isCompleted(), false);
            EXPECT_EQ(header.value().first, pairs[counter].first);
            EXPECT_EQ(header.value().second, pairs[counter].second);

            counter ++;
        } else {
            EXPECT_EQ(httpHeaderParser.isCompleted(), false);
        }
    }
}

TEST(HttpHeaderParser, TestIncorrectHttpHeaders) {

    std::string s = "Content-Typetext/plain\r";
    HttpHeaderParser httpHeaderParser;

    for (const char& c: s) {
        httpHeaderParser.parse(&c);
    }
    char extraChar = '\n';
    EXPECT_THROW({ httpHeaderParser.parse(&extraChar); }, std::invalid_argument);
    httpHeaderParser.reset();

    s = ":\r";
    for (const char& c: s) {
        httpHeaderParser.parse(&c);
    }
    extraChar = '\n';
    EXPECT_THROW({ httpHeaderParser.parse(&extraChar); }, std::invalid_argument);
    httpHeaderParser.reset();

    s = "    :  \r";
    for (const char& c: s) {
        httpHeaderParser.parse(&c);
    }
    extraChar = '\n';
    EXPECT_THROW({ httpHeaderParser.parse(&extraChar); }, std::invalid_argument);
    httpHeaderParser.reset();
}