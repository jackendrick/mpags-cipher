/*
 *MPAGS C++ work by JAMES KENDRICK JAK@HEP.PH.BHAM.AC.UK
 *Indentation may not be consistent due a variety of text editors being used
 */

#include <iostream>
#include <fstream>
#include "TransformChar.hpp"


bool processCommandLine(const int& argc, char* argv[], bool& wantHelp, bool& wantO, bool& wantI, bool& wantV, std::string& iValue, std::string& oValue, int& kValue);
void printHelp();
void printVersion(float vNumber);

bool readStream(std::string& savedString);
bool readStream(std::string& savedString, std::string inPutFileName);

bool outStream(std::string& savedString);
bool outStream(std::string& savedString, std::string outPutFileName);

std::string CaesarCipher(std::string& input, int k);

int main(int argc, char* argv[]){
  float vNumber = 0.10;
  bool wantHelp{false};
  bool wantO{false};
  bool wantI{false};
  bool wantV{false};
  int kValue{0};
  std::string oValue;
  std::string iValue;
  if(processCommandLine(argc, argv, wantHelp, wantO, wantI, wantV, iValue, oValue, kValue)==false){
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


  
 // The readStream functions handle the input of strings. It calls the transformChar function to ensure that all alphabet characters are capitalised and any other characters are ignored. 
  std::string bigString{""};
  bool inputSuccess{false};
  if(kValue==NULL){
    std::cout<<"A k has not been input. Please run the program again. \n";
    printHelp();
    return 1;
    }
  if (wantI){
    inputSuccess=readStream (bigString, iValue);
    }
  else{
    inputSuccess=readStream (bigString);
    }

  if (inputSuccess == false){
    return 1;
    }
  else {
     }
  std::string result{CaesarCipher(bigString, kValue)};
  // And now to out put the results
  bool outputSuccess{false}; 

  if (wantO){
    outputSuccess = outStream (result, oValue);
    }
  else {
    outputSuccess = outStream (result);
    }
  
  if (outputSuccess == false)
    {
    return 1;
    }
  else {
    return 0;  
    }
 //system("eject");
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
  const int stringLength{input.length()};
  std::string answer{""};
  for (int i = 0; i<stringLength; i++){
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



bool processCommandLine(const int& argc, char* argv[], bool& wantHelp, bool& wantO, bool& wantI, bool& wantV, std::string& iValue, std::string& oValue, int& kValue){
  for (int i=1; i<argc; i++){
    std::string tempString = argv[i];
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
    else if (tempString=="-E"&&(i<argc-1)){
      kValue= atoi(argv[i+1]);
      i++;
      }
    else if (tempString=="-D"&&(i<argc-1)){
      kValue = atoi(argv[i+1]) * -1;
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

  

