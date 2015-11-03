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

void CaesarCipher(std::string& input, int k);

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


  
 // The readStream functions handle the input of strings. It calls the transformChar function to ensure that all alphabet characters are capitalised and any other characters are ignored. 
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
  else {
     std::cout<<"Input read OK \n";
     }

CaesarCipher(bigString, 0);


  // And now to out put the results
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
  else {
    std::cout<<"Output produced OK \n";
    return 0;  
    }
 //system("eject");
}


void CaesarCipher(std::string& input, int k){

// Planning for homework:
// Edit the input so only characters are saved
// Have the input string saved as bigString - DONE
// Convert character string to an temporary integer array - DONE
// If option is do decrypt, k = -k
// Loop across each array element [i] = [i] + k - DONE
// Check wraparound using modulus sign (both above 25 & below 0)
// Convert back to character string / array
// Output the result
// Edit CL arguements

// Converting bigString to integer array.  
  const int stringLength{input.length()};
  int intArray [stringLength];
  
  for (int i = 0; i<stringLength; i++){
    int temp{input[i] + k - (int)'A'};
    intArray[i]=temp;
    }

  for (int i = 0; i<stringLength; i++){
    int temp{intArray[i]+(int)'A'};
    input[i]= (char)temp;
    }



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
  return true;
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

  

