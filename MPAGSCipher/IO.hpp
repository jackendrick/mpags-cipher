#ifndef MPAGSCIPHER_IO_HPP
#define MPAGSCIPHER_IO_CPP

#include <string>

std::string transformChar(const char inputChar);

template<typename T>
std::string read(T& inputStream){
    char inputChar {};
    std::string savedString;
    while (inputStream>>inputChar)  {
      savedString = savedString + transformChar(inputChar);
    }
    return savedString;
}


template<typename T>
void outPut(T& outputStream, std::string& savedString){
    outputStream<<savedString;
}

#endif