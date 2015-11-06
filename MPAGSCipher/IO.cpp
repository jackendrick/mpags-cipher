#include "IO.hpp"

std::string transformChar(char inputChar){
  std::string answer{""};
  
  if (isdigit(inputChar)){
    switch (inputChar){
      case '0':
	answer="ZERO";
	break;
      case '1':
	answer="ONE";
	break;
      case '2':
	answer="TWO";
	break;
      case '3':
	answer="THREE";
	break;
      case '4':
	answer="FOUR";
	break;
      case '5':
	answer="FIVE";
	break;
      case '6':
	answer="SIX";
	break;
      case '7':
	answer="SEVEN";
	break;
      case '8':
	answer="EIGHT";
	break;
      case '9':
	answer="NINE";
	break;
      }
    }
    // If not number, check if character
  else if (isalpha(inputChar)){
    //std::cout<<"Passed alpha test"<<std::endl;
    if (islower(inputChar)){
	//std::cout<<"Is lower case"<<std::endl;
      char tempchar = toupper(inputChar);
      answer = tempchar;
      }
    else {
      //std::cout<<"Is upper case"<<std::endl;
    answer = inputChar;
    }
      //If lower case character
      //Convert to upper case
      // Add character to string
  }
    //std::cout<<"End of funciton"<<std::endl;
  return answer;
    // Other wise, do nothing
}







