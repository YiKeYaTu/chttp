//
// Created by lc on 2021/12/12.
//

#include <gtest/gtest.h>
#include <iostream>
#include <optional>
#include "parsers/LineParser.h"

void testOneLine() {
    std::string oneLine = "GET / HTTP/1.1\r\n";
    LineParser lineParser;
    std::optional<std::string> line;

    for (char& c: oneLine) {
        try {
            line = lineParser.parse(&c);
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
    ASSERT_EQ(line.has_value(), true);
    ASSERT_EQ(line.value(), "GET / HTTP/1.1");
}

void testUnendingLine() {
    std::string unendingLine = "GET / HTTP/1.1\r";
    LineParser lineParser;
    std::optional<std::string> line;

    for (char& c: unendingLine) {
        try {
            line = lineParser.parse(&c);
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    ASSERT_EQ(line.has_value(), false);
}

void testContinuedLine() {
    std::string unendingLine = "GET / HTTP/1.1\r";
    LineParser lineParser;
    std::optional<std::string> line;

    for (char& c: unendingLine) {
        try {
            line = lineParser.parse(&c);
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    ASSERT_EQ(line.has_value(), false);

    char extraChar = '\n';

    line = lineParser.parse(&extraChar);
    ASSERT_EQ(line.has_value(), true);
    ASSERT_EQ(line.value(), "GET / HTTP/1.1");
}

void testIncorrectLine() {
    std::string unendingLine = "GET / HTTP/1.1\r";
    LineParser lineParser;
    std::optional<std::string> line;

    for (char& c: unendingLine) {
        line = lineParser.parse(&c);
    }

    char extraChar = 'G';
    EXPECT_THROW({
        lineParser.parse(&extraChar);
    }, std::invalid_argument);
    EXPECT_EQ(lineParser.isCompleted(), true);
}

void testResetIncorrectLine() {
    std::string unendingLine = "GET / HTTP/1.1\r";
    LineParser lineParser;
    std::optional<std::string> line;

    for (char& c: unendingLine) {
        line = lineParser.parse(&c);
    }

    char extraChar = 'G';
    EXPECT_THROW({ lineParser.parse(&extraChar); }, std::invalid_argument);
    EXPECT_EQ(lineParser.isCompleted(), true);

    lineParser.reset();
    EXPECT_EQ(lineParser.isCompleted(), false);

    std::string oneLine = "GET / HTTP/1.1\r\n";

    for (char& c: oneLine) {
        try {
            line = lineParser.parse(&c);
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
    ASSERT_EQ(line.has_value(), true);
    ASSERT_EQ(line.value(), "GET / HTTP/1.1");
}

TEST(LineParserTest, BasicAssertions) {
    testOneLine();
    testUnendingLine();
    testContinuedLine();
    testIncorrectLine();
    testResetIncorrectLine();
}