#include "CipherFactory.hpp"
#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"


  
std::unique_ptr<Cipher> CipherFactory(const CipherType type, std::string key){
  
  switch (type) {
    case CipherType::Playfair :
      return std::make_unique<PlayfairCipherClass>(key);
    
    case CipherType::Caesar :
      return std::make_unique<CaesarCipherClass>(std::stoi(key));
  
    
    }
    
}