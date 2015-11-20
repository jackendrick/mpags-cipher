#include "commandLine.hpp"
#include "CipherFactory.hpp"
#include <iostream>

bool processCommandLine(const int& argc, char* argv[], CommandLineArgs& arguements){
  for (int i=1; i<argc; i++){
    std::string tempString = argv[i];
    if ((tempString=="--help")||(tempString=="-h")){
      arguements.wantHelp = true;
      return true;
      }
    else if (tempString=="--version"){
      arguements.wantVers = true;
      return true;
      }
    else if (tempString=="-cipher"&&(i<argc-1)){
      std::string choice{argv[i+1]};
      if (choice=="caesar") {
	arguements.cipherChoice=CipherType::Caesar;
	i++;
	}
      else if (choice=="playfair") {
	arguements.cipherChoice=CipherType::Playfair;
	i++;
	}
      else {
	std::cout<<"False part \n";
	return false;
	}
      }
    else if (tempString=="-o"&&(i<argc-1)){
      arguements.oValue=argv[i+1];
      i++;
      }
    else if (tempString=="-i"&&(i<argc-1)){
      arguements.iValue=argv[i+1];
      i++;
      }
    else if (tempString=="-E"&&(i<argc-1)){
     //int temp = atoi(argv[i+1])%26;
      arguements.kValue= argv[i+1];
      arguements.encOrDec=true;
      i++;
      }
    else if (tempString=="-D"&&(i<argc-1)){
      //int temp = atoi(argv[i+1])%26;
      arguements.kValue = argv[i+1];
      arguements.encOrDec=false;
      i++;
      }
    else {
      return false;
      }
    }   
    return true;
  }
  
void printHelp(){  
    std::cout<<"HELP:"<<"\n";
    std::cout<<"Please run mpags-cipher. Add -E <k> for encryption OR -D <k> for decryption. Default IO is through the command line. \n \n";
    std::cout<<"For command line entry, input the string once the program is running. CTRL+D to end input. \n \n";
    std::cout<<"Additional command line arguements include: \n";
    std::cout<<"--version for verion number \n";
    std::cout<<"-i for file input, followed by the input file name \n";
    std::cout<<"-o for file output, followed by the output file name \n";
    }
    
    
void printVersion (float vNumber){
   std::cout<<"Version number is: "<<vNumber<<"\n";
   }