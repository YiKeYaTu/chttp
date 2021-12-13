//
// Created by lc on 2021/12/13.
//

#ifndef CHTTP_STRINGUTILS_H
#define CHTTP_STRINGUTILS_H

#include <vector>
#include <string>

std::string& trimLeft(std::string&);
std::string& trimRight(std::string&);
std::string& trim(std::string&);

std::vector<std::string> split(std::string&);

#endif //CHTTP_STRINGUTILS_H
