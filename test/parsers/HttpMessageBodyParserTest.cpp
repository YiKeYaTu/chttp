//
// Created by lc on 2021/12/17.
//

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <cstddef>
#include "parsers/HttpMessageBodyParser.h"

TEST(HttpMessageBodyParser, TestFixedLengthHttpMessageBody) {
    auto a = HttpMessageBodyParser::getInstance(10);
    std::string string = "ABCDEFGHIJ";
    std::optional<HttpMessageBody> optHttpMessageBody;

    for (const char& c : string) {
        optHttpMessageBody = a->parse(&c);
    }

    ASSERT_EQ(optHttpMessageBody.has_value(), true);
    ASSERT_EQ(optHttpMessageBody.value().getMessageBodyWithString(), "ABCDEFGHIJ");

    a->reset();
    for (const char& c : string) {
        optHttpMessageBody = a->parse(&c);
    }

    ASSERT_EQ(optHttpMessageBody.has_value(), true);
    ASSERT_EQ(optHttpMessageBody.value().getMessageBodyWithString(), "ABCDEFGHIJ");

}


TEST(HttpMessageBodyParser, TestParseAfterComplete) {
    auto a = HttpMessageBodyParser::getInstance(10);
    std::string string = "ABCDEFGHIJ";
    std::optional<HttpMessageBody> optHttpMessageBody;

    for (const char& c : string) {
        optHttpMessageBody = a->parse(&c);
    }

    char c = 'C';
    EXPECT_THROW({ a->parse(&c); }, std::logic_error);
}
