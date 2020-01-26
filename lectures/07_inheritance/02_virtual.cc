#include "ap_error.h"
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(!(weight < 0)) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor

  virtual void speak() const = 0;  // pure virtual function ==> abstract class
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

// if you instanziate an object that is virtual, the compile tells you the error
    
  virtual ~Animal() {}  // why? see file 03_virtual_destructor.cc
};

struct Dog : public Animal {
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

struct Snake : public Animal {
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override { // override(children) -> virtual(base)
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

// this is called polymorphism
void print_animal(const Animal& a) noexcept {    // this function now works as expected (see previous code)
  std::cout << "throught ref\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Snake s{true};
    s.info();
    s.speak();

    std::cout << std::endl;

    Animal* p = new Snake{1, 2.3, false};

    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    std::cout << std::endl;

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}


// empty class: both of the two cout print 1
// if I set "virtual void bar", the compiler prints 8,8: there are pointers inside of this class! Penalty: class is bigger and you have to jump in memory
      
// When you put virtual somewhere, a pointer is add

//  struct foo{
//      void bar() {std::cout << "in foo \n";}
//      };
//      struct derived: public foo{
//
//      };
//
//  int main() {
//      std::cout << sizeof(foo) << std::enld;
//        std::cout << sizeof(derived) << std::enld;
//  };
// --this is an example--
