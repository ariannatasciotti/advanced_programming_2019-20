#include <iostream>

enum color { red, yellow, green };   // define a type "color"
// enum color{red=0, yellow=1, green=2}; // equivalent

void dwim(const color c) {
  switch (c) {                                       // when we have a lot of if, the statement switch is very useful..                                                                                                 
                                                          // Switch(c) where c is the name of the variable
    case red:
      std::cout << "option 1: red\n";
      break;
    case yellow:
      std::cout << "option 2: yellow\n";
      break;
    case green:
      std::cout << "option 3: green\n";
      break;
    default:
      std::cout << "unknown option\n";  // should I exit the program?
      break;
  }
}

int main() {
  color opt{red};  // opt is the variable of the type color (enum)
  // opt = 3; // cannot assign int to enum
  int a{opt};  // but they implicitly converts to integers // i can initialize an integer with an enum

  dwim(opt);

  dwim(yellow);

  // dwim(2); // error
  dwim(color(2));  // works but why you may want to write this?

  dwim(color(6));  // ???    // this works but we don't have 6 colors: this sintacs is dangerous!

  return 0;
}
