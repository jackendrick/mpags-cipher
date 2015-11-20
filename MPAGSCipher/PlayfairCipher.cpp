#include "PlayfairCipher.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <functional>

PlayfairCipherClass::PlayfairCipherClass(const std::string inputKey){
  setKey(inputKey);
  }

std::string PlayfairCipherClass::encrypt(const std::string& input) const{
  std::string interCopy{input}; // An intermediate copy of the input
  //std::cout<<"intermediate = \n \n "<<interCopy<<"\n \n";
  // Check input
  std::transform(interCopy.begin(), interCopy.end(), interCopy.begin(), toupper);
  auto iter = std::remove_if(interCopy.begin(), interCopy.end(), [] (char x){return !isalpha(x);});
  interCopy.erase(iter, interCopy.end());

  // Change J -> I
  std::transform(interCopy.begin(), interCopy.end(), interCopy.begin(), [&] (char x) {if (x=='J')return 'I'; else return x;} );
  //std::cout<<"intermediate = \n \n "<<interCopy<<"\n \n";  
  // Add x to repeated letters
  std::string secInterCopy{};
  
  for (int i = 0; i < interCopy.size(); i++){
    secInterCopy += interCopy[i];
    if(i<interCopy.size()){
      if(interCopy[i]==interCopy[i+1]){
	  secInterCopy+='X';	
	}
      }
    }
  //std::cout<<"intermediate2 = \n \n "<<secInterCopy<<"\n \n";  
  // If length is odd, add another z
  if ( (secInterCopy.size()%2)==1){
    secInterCopy+='Z';
  }
  // Loop over input in digraphs
  std::string result{};
  for (int i =0; i<secInterCopy.size(); i+=2){
    digraph temp{secInterCopy[i],secInterCopy[i+1]};
    digraph res{encryptDigraph(temp)};
    result += res.first;
    result += res.second;
    }

 
  // Return result
  return result;
  }
  
digraph PlayfairCipherClass::encryptDigraph(digraph inputDigraph) const{
  const char char1{inputDigraph.first};
  const char char2{inputDigraph.second};
  if (char1==char2){std::cout<<"Error digraph has identical characters \n";}

  intPair pair1{mapChar.at(char1)};
  intPair pair2{mapChar.at(char2)};
  
  int char1X{pair1.first};
  int char1Y{pair1.second};
  
  int char2X{pair2.first};
  int char2Y{pair2.second};
  
  if (char1Y==char2Y){
    if (char1X==4){
      char1X=0;
      }
    else char1X++;
    if (char2X==4){
      char2X=0;
      }
    else char2X++;
    }
  else if (char1X==char2X){
    if (char1Y==4){
      char1Y=0;
      }
    else char1Y++;
    if (char2Y==4){
      char2Y=0;
      }
    else char2Y++;
    }     
  else{
    int temp = char1X;
    char1X = char2X;
    char2X = temp;   
    }
    
  intPair resPair1(char1X, char1Y);
  intPair resPair2(char2X, char2Y);
  
  char resChar1{mapInt.at(resPair1)};
  char resChar2{mapInt.at(resPair2)};
 
  digraph outputDigraph{resChar1, resChar2};
  return outputDigraph;
  
  }

digraph PlayfairCipherClass::decryptDigraph(digraph inputDigraph) const{
  char char1{inputDigraph.first};
  char char2{inputDigraph.second};
  if (char1==char2){std::cout<<"Error digraph has identical characters \n";}

  intPair pair1{mapChar.at(char1)};
  intPair pair2{mapChar.at(char2)};
  
  int char1X{pair1.first};
  int char1Y{pair1.second};
  
  int char2X{pair2.first};
  int char2Y{pair2.second};
  
  if (char1Y==char2Y){
    if (char1X==0){
      char1X=4;
      }
    else char1X--;
    if (char2X==0){
      char2X=4;
      }
    else char2X--;
    }
  else if (char1X==char2X){
    if (char1Y==0){
      char1Y=4;
      }
    else char1Y--;
    if (char2Y==0){
      char2Y=4;
      }
    else char2Y--;
    }     
  else{
    int temp = char1X;
    char1X = char2X;
    char2X = temp;   
    }
    
  intPair resPair1(char1X, char1Y);
  intPair resPair2(char2X, char2Y);
  
  char resChar1{mapInt.at(resPair1)};
  char resChar2{mapInt.at(resPair2)};
 
  digraph outputDigraph{resChar1, resChar2};
  return outputDigraph;
  
  }
  
std::string PlayfairCipherClass::decrypt(const std::string& input) const{
  // Loop over input in digraphs
  std::string result{};
  for (int i =0; i<input.size(); i+=2){
    digraph temp{input[i],input[i+1]};
    digraph res{decryptDigraph(temp)};
    result += res.first;
    result += res.second;
    }

 
  // Return result
  return result;
  }

void PlayfairCipherClass::setKey(std::string inputKey){
  // Store the original inputKey
  std::string savedKey{inputKey};
  
  // Append the alphabet
  std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  savedKey = savedKey + alphabet;
  
  // Make srue the key is upper
  std::transform(savedKey.begin(), savedKey.end(), savedKey.begin(), toupper);
  
  // Remove the non-alpha characters
  auto iter = std::remove_if(savedKey.begin(), savedKey.end(), [] (char x){return !isalpha(x);});
  savedKey.erase(iter, savedKey.end());
  
  // Change J -> I
  std::transform(savedKey.begin(), savedKey.end(), savedKey.begin(), [&] (char x) {if (x=='J')return 'I'; else return x;} );
  
  // Remove duplicated letters
  std::string duplicate{};
  auto iterDup = std::remove_if(savedKey.begin(), savedKey.end(), [&] (char x) {
    std::size_t found = duplicate.find(x);
    if (found == std::string::npos){
      duplicate = duplicate + x;
      return false;
    }
    else {
      return true;
    }
  });
  savedKey.erase(iterDup, savedKey.end() );
  
  // For testing:
  //std::cout<<"Saved key = "<<savedKey<<"\n";
  // Store the coords of each letters
  for (int i = 0; i < 25; i++){
    int xCoord{i%5};
    int yCoord{(i-xCoord)/5};
    mapChar[ savedKey[i] ] = intPair(xCoord, yCoord);
    mapInt[ intPair(xCoord, yCoord)] = savedKey[i];
    //std::cout << savedKey[i] << " has coordinates (" << xCoord << "," << yCoord << ") \n";
  }
  // Store the playfair cipher key map
  // Check the cipher:
  std::cout<<"\n \n Cipher key: \n";
  for (int y = 0; y <5; y++){
    for (int x =0; x <5; x++){
      intPair temp(x,y);
      std::cout<<mapInt[temp]<<" ";
     
    }
    std::cout<<"\n";
  }
  std::cout<<"\n \n \n";
  }
  
 