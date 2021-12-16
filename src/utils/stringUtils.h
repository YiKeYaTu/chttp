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

class StringSplittingIterator: public std::iterator<std::input_iterator_tag, std::string> {
public:
    StringSplittingIterator(const std::string&, const std::string&);

    bool hasNext() const;

    StringSplittingIterator& operator++();
    const StringSplittingIterator operator++(int);
    const std::string operator*() const;
private:
    const std::string& input;
    const std::string& separator;

    std::string::size_type left = 0;
    std::string::size_type right = 0;

    std::string::size_type findNextSeparator() const;
};

#endif //CHTTP_STRINGUTILS_H
