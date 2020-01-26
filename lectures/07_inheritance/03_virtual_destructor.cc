#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
 virtual ~Base() { std::cout << "~Base\n"; }  // if some classes inherited from the base class put the virtual in order to deconstruct also the Derived class
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }  // construct and deconstruct d: it is put into a scope

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p;  // in this way, it only destroy the Base class since p is a pointer to Base

  return 0;
}

// First construct Base, then Derived and then first deconstruct Derived and then Base


