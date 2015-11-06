/*
 *MPAGS C++ work by JAMES KENDRICK JAK@HEP.PH.BHAM.AC.UK
 *Indentation may not be consistent due a variety of text editors being used
 */

#include <iostream>
#include <fstream>
#include "IO.hpp"
#include "commandLine.hpp"
#include "CaesarCipher.hpp"



int main(int argc, char* argv[]){
  float vNumber=0.3;
  CommandLineArgs myArgs{};
  if(processCommandLine(argc, argv, myArgs)){
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


  
 // The readStream functions handle the input of strings. It calls the transformChar function to ensure that all alphabet characters are capitalised and any other characters are ignored. 
  std::string bigString{""};
  if (myArgs.iValue!=""){
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
  CaesarCipherClass myCaesar {myArgs.kValue};
  std::string result{CaesarCipher(bigString, myCaesar.getk())};
  // And now to out put the results
  if (myArgs.oValue!=""){
    outPut(std::cout, bigString);
    }
  else {
    std::ofstream out_file{myArgs.oValue};
    if (out_file.good()){
      outPut (out_file, bigString);
    }
    else {
      return 1;
    }
  }

}






