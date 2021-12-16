//
// Created by lc on 2021/12/16.
//

#ifndef CHTTP_URI_H
#define CHTTP_URI_H

#include <string>

class URI {
public:
    static URI create(const std::string&);

    const std::string &getUriString() const;

private:
    URI(const std::string&);
    std::string uriString;
};


#endif //CHTTP_URI_H
