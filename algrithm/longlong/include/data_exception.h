#ifndef _DATA_EXCEPTION_H_
#define _DATA_EXCEPTION_H_

#include <exception>
#include <string>

namespace ll {

namespace algorithm {

using std::string;
using std::exception;

class DataException : public exception {
  public:
    DataException(const string& msg)
        : message { msg } {
    }

    const char* what() noexcept {
        return message.c_str();
    }

  private:
    string message;
};

}

}

#endif