#include <iostream>
int main()
{
 // This is a comment
 /* This is a
 Multiline comment */

 std::cout << "Friday friday \n Gotta get down on friday \n";

 int numA{1};
 int numB{3};
 const double douA{1.5};
 int numC{numB*douA};
 numA=3;
 auto booA{true};
 std::cout<< "double/int: " <<douA/numB<<"\n";
 
 //system("eject");
}
