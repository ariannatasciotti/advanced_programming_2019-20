#include <iostream>

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope; with this command we are able to call the int function and not the char one
  void f(char x) { std::cout << "char " << x << std::endl; }
// we are not overriding: the types are different (char and int), we are overloading
};

int main() {
  bar b;
  b.f(33);
}
