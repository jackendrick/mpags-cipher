#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

enum class CipherType{Playfair, Caesar};

#include <memory>
#include "Cipher.hpp"

std::unique_ptr<Cipher> CipherFactory(const CipherType type, std::string key);

#endif