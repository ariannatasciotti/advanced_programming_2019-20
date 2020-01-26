#include <greetings.h>
#include <iostream>

void print_greetings() {
#ifdef ITALIANO
  std::cout << "Benvenuti al corso di Advanced Programming\n";
#endif

#ifdef ENGLISH
  std::cout << "Welcome to the Advanced Programming course\n";
#endif
}


// when i compile a code, i don't get an executable but an object file
// if i have more than one source file, i can compile each source file in parallel and then i can link the object file
// if you want to generate a shared library, you have to add another flag at compile time -fPIC (position independent code)

// the code to generate a library is:
//c++ greetings.o conclusion.o -shared -o libgreetings.so

// if you have a lot of file, it can be a very waste of time doing this for each one... so, MAKEFILE

// macro for the pre processor generated with -D

// In makefile: "src/greetings.o: include/greetings.h" <- tell to the makefile to recompile the code if and only if the header greetings.h is changed




