//
// Created by lc on 2021/12/12.
//

#include "parsers/LineParser.h"
#include "parsers/FixedLengthLineParser.h"

int main()
{
    LineParser lineParser;
//    lineParser.parse('c');

    FixedLengthLineParser fixedLengthLineParser;
    fixedLengthLineParser.parse('c');
//    lineParser.parse('c');
    return 0;
}