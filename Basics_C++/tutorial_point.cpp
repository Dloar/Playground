//#include <iostream>
//using namespace std;
//
//int main() {
//   cout << "Size of char : " << sizeof(char) << endl;
//   cout << "Size of int : " << sizeof(int) << endl;
//   cout << "Size of short int : " << sizeof(short int) << endl;
//   cout << "Size of long int : " << sizeof(long int) << endl;
//   cout << "Size of float : " << sizeof(float) << endl;
//   cout << "Size of double : " << sizeof(double) << endl;
//   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
//
//   return 0;
//}
//
//#include <iostream>
//using namespace std;
//// These are global variables
//#define LENGTH 10
//#define WIDTH  5
//#define NEWLINE '\n'
//
//int main() {
//    // This are local variables
//   int area;
//
//   area = LENGTH * WIDTH;
//   cout << area;
//   cout << NEWLINE;
//   return 0;
//}
//
//#include <iostream>
//using namespace std;
//
///* This program shows the difference between
//   * signed and unsigned integers.
//*/
//int main() {
//   short int i;           // a signed short integer
//   short unsigned int j;  // an unsigned short integer
//
//   j = 50000;
//
//   i = j;
//   cout << i << " " << j << "\n";
//
//   return 0;
//}

#include <iostream>

// Function declaration
void func(void);

static int count = 10; /* Global variable */

main() {
   while(count--) {
      func();
   }

   return 0;
}

// Function definition
void func( void ) {
   static int i = 5; // local static variable
   i++;
   std::cout << "i is " << i ;
   std::cout << " and count is " << count << std::endl;
}