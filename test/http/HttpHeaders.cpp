//
// Created by lc on 2021/12/14.
//

#include <gtest/gtest.h>
#include "http/HttpHeaders.h"

TEST(HttpHeaders, TestCopyConstructor) {
    HttpHeaders httpHeaders;
    httpHeaders.setHeader("k", "v");
}