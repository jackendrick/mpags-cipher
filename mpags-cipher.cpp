#include <iostream>
int main()
{
  std::string bigString{""};
  char in_char ('x');
  while (std::cin>>in_char)
  {
    // While loop innit
    // Test if number
    if (isdigit(in_char)){
      //Convert number to text
      //Add string to bigstring
      //const int  num = in_char;
      std::string numString{""};
      switch (in_char){
      case '0':
	numString="ZERO";
	break;
      case '1':
	numString="ONE";
	break;
      case '2':
	numString="TWO";
	break;
      case '3':
	numString="THREE";
	break;
      case '4':
	numString="FOUR";
	break;
      case '5':
	numString="FIVE";
	break;
      case '6':
	numString="SIX";
	break;
      case '7':
	numString="SEVEN";
	break;
      case '8':
	numString="EIGHT";
	break;
      case '9':
	numString="NINE";
	break;
      }
      // std::cout<<"b = "<<bigString<<" + n = "<<numString;
      bigString = bigString+numString;
      //std::cout<<" = "<<bigString<<"\n";

    }
    // If not number, check if character
    else if (isalpha(in_char)){
      if (islower(in_char)){
	char tempchar = toupper(in_char);
	bigString = bigString + tempchar;
      }
      else {
	bigString = bigString + in_char;
	}
      //If lower case character
      //Convert to upper case
      // Add character to string
    }
    // Other wise, do nothing
  }
  std::cout<<bigString<<"\n";
 
 //system("eject");
}
