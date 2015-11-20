#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP
#include <string>
#include "Cipher.hpp"
/**
 * CaesarCipherClass has a key.
 * Use it by ...
 */
class CaesarCipherClass : public Cipher {
  public:
    /**
     * Create a new instance of a caesar cipher.
     * \param inputk the value of the key (positive for encryption and negative for decrytion) 
     */
    CaesarCipherClass(const int inputk);
    virtual std::string encrypt(const std::string& input) const override;
    virtual std::string decrypt(const std::string& input) const override;     


  private:
    /// This is the key of the cipher
    const int k = 0;
    std::string CaesarCipher(std::string& input, int key, bool encOrDec) const;
    /// \return the value of the key
    int getk() const;
};


#endif