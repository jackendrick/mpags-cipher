#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#include <string>
#include <map>
#include "Cipher.hpp"

using intPair = std::pair<int,int>;
using digraph = std::pair<char, char>;
using Str2IntMap = std::map<char, intPair >;
using Int2StrMap = std::map<intPair, char>;

class PlayfairCipherClass : public Cipher{
  public:
    PlayfairCipherClass(const std::string inputKey);
    virtual std::string encrypt(const std::string& input) const override;
    virtual std::string decrypt(const std::string& input) const override;    
    
  private:
    //std::string savedKey;  
    Str2IntMap mapChar;
    Int2StrMap mapInt;
    digraph encryptDigraph(digraph inputDigraph) const;
    digraph decryptDigraph(digraph inputDigraph) const;
    void setKey(std::string inputKey);
  
};


#endif
