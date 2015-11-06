#include "CaesarCipher.hpp"
#include <string>

CaesarCipherClass::CaesarCipherClass(const int inputk)
  : k{inputk}
{  
}

int CaesarCipherClass::getk() const {
  return k;
  }

std::string CaesarCipher(std::string& input, int k){
// Planning for homework:
// Edit the input so only characters are saved - DONE
// Have the input string saved as bigString - DONE
// Convert character string to an temporary integer array - DONE
// If option is do decrypt, k = -k - DONE
// Loop across each array element [i] = [i] + k - DONE
// Check wraparound using modulus sign (both above 25 & below 0) - DONE, NEEDS TESTING
// Convert back to character string / array - DONE
// Output the result - DONE
// Edit CL arguements - DONE

// Converting bigString to integer array.  
  std::string answer{""};
  for (int i = 0; i<input.length(); i++){
    int temp{input[i] + k - (int)'A'};
    if (temp<0){
      temp = temp + 26;
      }
    else if (temp>25){
      temp=temp%26;
      }
    temp = temp + (int)'A';  
    char tempC = temp;
    answer = answer + tempC; 
    }
  return answer;

}