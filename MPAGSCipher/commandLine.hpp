#ifndef MPAGSCIPHER_COMMANDLINE_HPP
#define MPAGSCIPHER_COMMANDLINE_HPP

#include <string>
struct CommandLineArgs{
  bool wantHelp=false;
  bool wantVers=false;
  std::string iValue="";
  std::string oValue="";
  int kValue=0;
};

bool processCommandLine(const int& argc, char* argv[], CommandLineArgs& arguements);
void printHelp();
void printVersion(float vNumber);

#endif