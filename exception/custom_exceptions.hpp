#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <iostream>
using namespace std;

class no_element_list : public std::exception {
    private:
        string message;
    public:
        explicit no_element_list(const string& msg) : message{msg} {}
        const char* what() const noexcept override {
            return message.c_str();
        }
};

#endif