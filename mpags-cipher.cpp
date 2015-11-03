#include <iostream>
#include <fstream>
#include "TransformChar.hpp"


bool processCommandLine(const int& argc, char* argv[], bool& wantHelp, bool& wantO, bool& wantI, bool& wantV, std::string& iValue, std::string& oValue);
void printHelp();
void printVersion(float vNumber);

bool readStream(std::string& savedString);
bool readStream(std::string& savedString, std::string inPutFileName);

bool outStream(std::string& savedString);
bool outStream(std::string& savedString, std::string outPutFileName);

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
    printHelp();
    return 0;
    }
  if (wantV){
    printVersion(vNumber);
    return 0;
    }

// Commented unneed cout sections
/*   *  if (wantO){
    std::cout<<"Output file is: "<<oValue<<"\n";
    }
  if (wantI){
    std::cout<<"Input file is: "<<iValue<<"\n";
    }
*/    


  
  
  std::string bigString{""};
  bool inputSuccess{false};
  if (wantI){
    inputSuccess=readStream (bigString, iValue);
    }
  else{
    inputSuccess=readStream (bigString);
    }

  if (inputSuccess == false){
    std::cout<<"Input failed \n";
    return 1;
    }
 
  bool outputSuccess{false}; 
  if (wantO){
    outputSuccess = outStream (bigString, oValue);
    }
  else {
    outputSuccess = outStream (bigString);
    }
  
  if (outputSuccess == false)
    {
    std::cout<<"Output failed \n";
    return 1;
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

void printHelp(){  
    std::cout<<"HELP:"<<"\n";
    std::cout<<"Please run mpags-cipher. Additional command line arguements include: \n";
    std::cout<<"--version for verion number \n";
    std::cout<<"-i for file input, followed by the input file name \n";
    std::cout<<"-o for file output, followed by the output file name \n";
    std::cout<<"Defaults allow for command line entry & return of results";
   }

void printVersion (float vNumber){
    std::cout<<"Version number is: "<<vNumber<<"\n";
  }

bool readStream(std::string& savedString){
    char inputChar {};
    while (std::cin>>inputChar)  {
      savedString = savedString + transformChar(inputChar);
    }
    return true;
    }

bool readStream(std::string& savedString, std::string inPutFileName){
    std::ifstream in_file {inPutFileName};
    bool ok_to_read = in_file.good();
    if (ok_to_read==false){
      std::cout<<"Input file not OK to read \n";
      return false;
    }
    char inputChar{};
    while (in_file>>inputChar) {
      savedString = savedString+transformChar(inputChar);   
    }
    return true;    
  }


bool outStream(std::string& savedString){
  std::cout<<savedString<<"\n";
  }

bool outStream(std::string& savedString, std::string outPutFileName){
  std::ofstream out_file {outPutFileName};
  bool ok_to_write = out_file.good();
  if (ok_to_write==false){
    std::cout<<"Output file not OK to write \n";
    return false;
    }
  else {
    out_file<<savedString<<"\n";    
    return true;
    }
  }

  

