#include <iostream>

// the base class is templated
template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

template <typename T>
struct Derived : public Base<T> {
  void bar() const { this->foo(); }  // this is a pointer to myself: if my base class is templated, use this in order to avoid compile errors
};

int main() {
  Derived<int> d;
  d.bar();
}
