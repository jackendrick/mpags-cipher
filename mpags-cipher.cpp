/*
 *MPAGS C++ work by JAMES KENDRICK JAK@HEP.PH.BHAM.AC.UK
 *Indentation may not be consistent due a variety of text editors being used
 */

#include <iostream>
#include <fstream>
#include "IO.hpp"
#include "commandLine.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"



int main(int argc, char* argv[]){
  float vNumber=0.3;
  CommandLineArgs myArgs{};
  if(!processCommandLine(argc, argv, myArgs)){
    std::cout<<"ERROR processing command line"<<"\n";
    return 1;
    }
  if (myArgs.wantHelp){
    printHelp();
    return 0;
    }
  if (myArgs.wantVers){
    printVersion(vNumber);
    return 0;
    }

  //std::cout<<"Command line inputted \n iValue = "<<(myArgs.iValue=="")<<"\n";

 // The readStream functions handle the input of strings. It calls the transformChar function to ensure that all alphabet characters are capitalised and any other characters are ignored. 
  std::string bigString{""};
  if (myArgs.iValue == ""){
    bigString= read(std::cin);
    }
  else{
    std::ifstream in_file {myArgs.iValue};
    if (in_file.good()){
      bigString=read(in_file);
      }
    else {
      std::cout<<"Input file not OK to read \n";
      return 1;
      }
    }
  //std::cout<<"Cipher choice = "<<myArgs.cipherChoice<<"\n";
  std::string result; 
  
  
  
  auto myCipher = CipherFactory(myArgs.cipherChoice, myArgs.kValue);    
  
  if (myArgs.encOrDec) result = myCipher->encrypt(bigString);
  else if (myArgs.encOrDec == false) result = myCipher->decrypt(bigString);
  else std::cout<<"ERROR: Not sure whether to encrypt or decrypt \n";
  
  // And now to out put the results
  if (myArgs.oValue==""){
    std::cout<<"Result is here: "<<result<<"\n";
    outPut(std::cout, result);
    }
  else {
    std::ofstream out_file{myArgs.oValue};
    if (out_file.good()){
      outPut (out_file, result);
    }
    else {
      return 1;
    }
  }

}






