//
// Created by lc on 2021/12/13.
//

#include <gtest/gtest.h>
#include <optional>
#include "parsers/FixedLengthLineParser.h"

TEST(FixedLengthLineParser, TestOneLine) {
    FixedLengthLineParser fixedLengthLineParser(16);
    std::string string = "This is a Line\r\n\r\n";
    std::optional<std::string> fixedLengthLine;

    for (const char c: string) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }

    ASSERT_EQ(fixedLengthLine.has_value(), true);
    ASSERT_EQ(fixedLengthLine.value(), "This is a Line\r\n");
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), true);
}

TEST(FixedLengthLineParser, TestUnendingLine) {
    FixedLengthLineParser fixedLengthLineParser(10);
    std::string string = "This\r\n";
    std::optional<std::string> fixedLengthLine;

    for (const char c: string) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }

    ASSERT_EQ(fixedLengthLine.has_value(), false);
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), false);
}


TEST(FixedLengthLineParser, TestContiunedLine) {
    FixedLengthLineParser fixedLengthLineParser(10);
    std::string string = "This\r\n";
    std::optional<std::string> fixedLengthLine;

    for (const char c: string) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }
    ASSERT_EQ(fixedLengthLine.has_value(), false);
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), false);

    std::string extraString = "This\r\n";
    for (const char c: extraString) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }

    ASSERT_EQ(fixedLengthLine.has_value(), true);
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), true);
    ASSERT_EQ(fixedLengthLine.value(), "This\r\nThis");

}

TEST(FixedLengthLineParser, TestResetLine) {
    FixedLengthLineParser fixedLengthLineParser(10);
    std::string string = "1234567890\r\n";
    std::optional<std::string> fixedLengthLine;

    for (const char c: string) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }
    ASSERT_EQ(fixedLengthLine.has_value(), true);
    ASSERT_EQ(fixedLengthLine.value(), "1234567890");
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), true);

    fixedLengthLineParser.reset();

    std::string extraString = "\r\n87654321\r\n";
    for (const char c: extraString) {
        fixedLengthLine = fixedLengthLineParser.parse(&c);
    }

    ASSERT_EQ(fixedLengthLine.has_value(), true);
    ASSERT_EQ(fixedLengthLineParser.isCompleted(), true);
    ASSERT_EQ(fixedLengthLine.value(), "\r\n87654321");

}


TEST(FixedLengthLineParser, TestExceptions) {
    FixedLengthLineParser fixedLengthLineParser(10);
    std::string string = "1234567890\r";
    std::optional<std::string> fixedLengthLine;

    for (const char c: string) {
        fixedLengthLineParser.parse(&c);
    }
    char extraChar = '\r';
    EXPECT_THROW({ fixedLengthLineParser.parse(&extraChar); }, std::invalid_argument);

    EXPECT_THROW({ fixedLengthLineParser.parse(&extraChar); }, std::logic_error);

    fixedLengthLineParser.reset();
    for (const char c: string) {
        fixedLengthLineParser.parse(&c);
    }
    extraChar = 'A';
    EXPECT_THROW({ fixedLengthLineParser.parse(&extraChar); }, std::logic_error);
}
