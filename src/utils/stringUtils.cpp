//
// Created by lc on 2021/12/13.
//

#include <algorithm>
#include "stringUtils.h"

std::string& trimLeft(std::string& s) {
    std::string::iterator left = s.begin();
    s.erase(left, left + s.find_first_not_of(' '));
    return s;
}

std::string& trimRight(std::string& s) {
    s.erase(s.begin() + s.find_last_not_of(' ') + 1, s.end());
    return s;
}

std::string& trim(std::string& s) {
    trimLeft(s);
    trimRight(s);
    return s;
}

std::vector<std::string> split(std::string&) {

}