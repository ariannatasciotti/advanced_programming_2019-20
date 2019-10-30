#include <iostream>

struct X {
  char member;      // builting type
};

int main() {
  X x1;                 // default ctor     instantiation of an object
  X x2{x1};             // copy ctor      constructing x2 that is a copy of x1
  X x3{std::move(x2)};  // move ctor    move from c++11         use circle braces when call a function
  X x4{};               // default ctor calling {} to each member      uniform initializer with curly braces
  x4 = x3;              // copy assignment         I have already construct x4 and now I copy x3 in x4
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment            all this function are constructed by the compiler
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}
