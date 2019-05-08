//#include <iostream>
//#include <string>
//int main()
//{
//    // ask for the person's name
//    std::cout << "Please enter your first name: ";
//    // read the name
//    std::string name;
//    std::cin >> name;
//    // build the message that we intend to write
//    const std::string greeting = "\nHello, " + name + "!\n";
//    std::cout << greeting << std::endl;
//    return 0;
//}

// While statment

#include <iostream>
using namespace std;

int main () {
   // Local variable declaration:
   int a = 0;
   std::cout << "Please enter value of a: ";
   std::cin >> a;

   // while loop execution
   while( a < 20 ) {
      cout << "value of a: " << a << endl;
      a++;
   }

   return 0;
}