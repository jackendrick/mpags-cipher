#include <iostream>
std::string transLit(char inputChar);

int main(int argc, char* argv[]){
  float vNumber = 1.02;
  bool wantHelp{false};
  bool wantO{false};
  bool wantI{false};
  bool wantV{false};
  std::string oValue;
  std::string iValue;
  for (int i=0; i<argc; i++){
    std::string tempString = argv[i];
    std::cout<<argv[i]<<"\n";
    if ((tempString=="--help")||(tempString=="-h")){
      wantHelp = true;
      }
    else if (tempString=="-o"){
      oValue=argv[i+1];
      wantO=true;
      }
    else if (tempString=="--version"){
      wantV=true;
      }
    else if (tempString=="-i"){
      iValue=argv[i+1];
      wantI=true;
      }
    }
  if (wantHelp){
    std::cout<<"HAHAHA YOU NEED HELP"<<"\n";
    }
  if (wantO){
    std::cout<<"Output file is: "<<oValue<<"\n";
    }
  if (wantI){
    std::cout<<"Input file is: "<<iValue<<"\n";
    }
  if (wantV){
    std::cout<<"Version number is: "<<vNumber<<"\n";
    }
  
  std::string bigString{""};
  char in_char ('x');
  while (std::cin>>in_char)  {
    bigString += transLit(in_char);
    }
  std::cout<<bigString<<"\n";
 
 //system("eject");
}


std::string transLit(char inputChar){
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