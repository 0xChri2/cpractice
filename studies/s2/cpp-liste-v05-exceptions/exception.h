#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <string>

class Exception {
private :
    std::string _error;
public :
    Exception(std::string error);

    std::string toString();
};

#endif