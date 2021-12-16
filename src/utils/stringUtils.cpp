//
// Created by lc on 2021/12/13.
//

#include <algorithm>
#include <iostream>
#include <stdexcept>
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

StringSplittingIterator::StringSplittingIterator(const std::string& input, const std::string& separator):
input(input), separator(separator) {
    right = findNextSeparator();
}

bool StringSplittingIterator::hasNext() const {
    return right == std::string::npos ? false : true;
}

std::string::size_type StringSplittingIterator::findNextSeparator() const {
    return input.find(separator, left);
}

const StringSplittingIterator StringSplittingIterator::operator++(int i) {
    auto old = *this;
    ++ (*this);
    return old;
}
StringSplittingIterator &StringSplittingIterator::operator++() {
    if (right == std::string::npos) {
        throw std::out_of_range("");
    }
    left = right + 1;
    right = findNextSeparator();
    return *this;
}

const std::string StringSplittingIterator::operator*() const {
    if (right == std::string::npos) {
        return input.substr(left);
    }
    return input.substr(left, right - left);
}