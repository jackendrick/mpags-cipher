#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP
#include <string>
/**
 * CaesarCipherClass has a key.
 * Use it by ...
 */
class CaesarCipherClass {
  public:
    /**
     * Create a new instance of a caesar cipher.
     * \param inputk the value of the key (positive for encryption and negative for decrytion) 
     */
    CaesarCipherClass(const int inputk);
    
    /// \return the value of the key
    int getk() const ;
  private:
    /// This is the key of the cipher
    const int k = 0;
};

std::string CaesarCipher(std::string& input, int k);

#endif