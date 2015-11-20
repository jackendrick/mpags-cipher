#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

class Cipher{
  public:
    Cipher() = default; // Constructor
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator = (const Cipher& rhs) = default;
    Cipher& operator = (Cipher&& rhs) = default;
    virtual ~Cipher() = default; // Destructor
    
    virtual std::string encrypt(const std::string& input) const = 0;
    virtual std::string decrypt(const std::string& input) const = 0;
  
  private:
  
  
};

#endif