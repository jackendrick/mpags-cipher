#include <iostream>
#include <fstream>
#include "TransformChar.hpp"


bool processCommandLine(const int& argc, char* argv[], bool& wantHelp, bool& wantO, bool& wantI, bool& wantV, std::string& iValue, std::string& oValue);


int main(int argc, char* argv[]){
  float vNumber = 0.10;
  bool wantHelp{false};
  bool wantO{false};
  bool wantI{false};
  bool wantV{false};
  std::string oValue;
  std::string iValue;
  if(processCommandLine(argc, argv, wantHelp, wantO, wantI, wantV, iValue, oValue)==false){
    std::cout<<"ERROR processing command line"<<"\n";
    return 1;
    }
  if (wantHelp){
    std::cout<<"HELP"<<"\n";
    return 0;
    }
  if (wantO){
    std::cout<<"Output file is: "<<oValue<<"\n";
    }
  if (wantI){
    std::cout<<"Input file is: "<<iValue<<"\n";
    }
  if (wantV){
    std::cout<<"Version number is: "<<vNumber<<"\n";
    return 0;
    }

    


  
  
  std::string bigString{""};
  
  if (wantI){
    std::ifstream in_file {iValue};
    bool ok_to_read = in_file.good();
    if (ok_to_read==false){
      std::cout<<"Input file not OK to read \n";
      return 1;
    }
    char inputChar{};
    while (in_file>>inputChar) {
      bigString = bigString+transformChar(inputChar);   
    }    
  }
  else {
    char inputChar {};
    while (std::cin>>inputChar)  {
      bigString = bigString + transformChar(inputChar);
    }
  }
  
  if (wantO){
    std::ofstream out_file {oValue};
    bool ok_to_write = out_file.good();
    if (ok_to_write==false){
      std::cout<<"Output file not OK to write \n";
      return 1;
      }
    out_file<<bigString<<"\n";    
    }
  else {
    std::cout<<bigString<<"\n";
  }
 //system("eject");
}





bool processCommandLine(const int& argc, char* argv[], bool& wantHelp, bool& wantO, bool& wantI, bool& wantV, std::string& iValue, std::string& oValue){
  for (int i=1; i<argc; i++){
    std::string tempString = argv[i];
    //std::cout<<argv[i]<<"\n";
    if ((tempString=="--help")||(tempString=="-h")){
      wantHelp = true;
      return true;
      }
    else if (tempString=="--version"){
      wantV=true;
      return true;
      }
    else if (tempString=="-o"&&(i<argc-1)){
      oValue=argv[i+1];
      wantO=true;
      i++;
      }
    else if (tempString=="-i"&&(i<argc-1)){
      iValue=argv[i+1];
      wantI=true;
      i++;
      }
    else {
      return false;
      }
    }
    
    return true;
  }