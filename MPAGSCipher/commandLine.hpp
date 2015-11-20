#ifndef MPAGSCIPHER_COMMANDLINE_HPP
#define MPAGSCIPHER_COMMANDLINE_HPP

#include <string>
#include "CipherFactory.hpp"

struct CommandLineArgs{
  bool wantHelp=false;
  bool wantVers=false;
  std::string iValue;
  std::string oValue;
  std::string kValue;
  CipherType cipherChoice = CipherType::Caesar;
  bool encOrDec; // Should be true for encryption, false for decryption. Not initialised on purpose
};

bool processCommandLine(const int& argc, char* argv[], CommandLineArgs& arguements);
void printHelp();
void printVersion(float vNumber);

#endif
