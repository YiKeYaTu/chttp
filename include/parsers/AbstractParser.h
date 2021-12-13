//
// Created by lc on 2021/12/12.
//

#ifndef CHTTP_ABSTRACTPARSER_H
#define CHTTP_ABSTRACTPARSER_H

#include <optional>
#include <stdexcept>
#include <map>
#include <string>

template<class T>
class AbstractParser {
public:
    std::optional<T> parse(const char*);
    void reset();
    bool isCompleted() const;
protected:
    std::string storedString;

    virtual std::optional<T> parseChar(const char*) = 0;
    virtual void resetStatus() = 0;

private:
    bool completedParse = false;
    void complete();
    void requiresNotComplete() const;
};

template<class T>
inline bool AbstractParser<T>::isCompleted() const {
    return completedParse;
}

template<class T>
inline std::optional<T> AbstractParser<T>::parse(const char* c) {
    requiresNotComplete();
    try {
        std::optional<T> o = parseChar(c);
        if (o.has_value()) {
            complete();
        }

        return o;
    } catch (std::invalid_argument& e) {
        complete();
        throw std::invalid_argument(e.what());
    }
}

template<class T>
inline void AbstractParser<T>::requiresNotComplete() const {
    if (completedParse == true) {
        throw std::logic_error("Parse process has already completed.");
    }
}

template<class T>
inline void AbstractParser<T>::complete() {
    requiresNotComplete();
    completedParse = true;
}

template<class T>
inline void AbstractParser<T>::reset() {
    storedString.clear();
    completedParse = false;
    resetStatus();
}
#endif //CHTTP_ABSTRACTPARSER_H
