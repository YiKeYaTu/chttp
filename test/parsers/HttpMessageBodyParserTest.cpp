//
// Created by lc on 2021/12/17.
//

#include <gtest/gtest.h>
#include <string>
#include "parsers/HttpMessageBodyParser.h"

TEST(HttpMessageBodyParser, TestFixedLengthHttpMessageBody) {
    auto a = HttpMessageBodyParser::getInstance(100);
}