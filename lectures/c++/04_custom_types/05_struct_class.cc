#include <array>
#include <iostream>
#include <vector>

// In classes i can put data and function.. In c++, 'struct' is equal to 'class', so a struct can accept both data and function.. the difference is about the visibility of the variables: in struct all the variables are PUBLIC, in classes the default visibility is PRIVATE.


struct Point_s {
  double x;
  double y;
  void print();
};  // note ; at the end of the declaration

void Point_s::print() {
  std::cout << "Structure. x = " << x << "; y = " << y << std::endl;
}

class Point_c {
  double x;
  double y;

 public:  // this change the defaul visibility
  void print() {
    std::cout << "Class. x = " << x << "; y = " << y << std::endl;
  }  // note no ; at the end
};   // note ; at the end

int main() {   // How can i access data?
  Point_s ps;  // Here I create an object called ps.. objects are instanziation of a class
  ps.x = 9.9;   // In this way, i access to the data (x,y)
  ps.y = 3. / 7;

  ps.print();

  Point_c pc;
  // pc.x =7.6; // error
  pc.print();  // I can access private data through public functions //Point_c is a class, Point_s is a struct.. so pc is try to access to something that is private and so it returns an error, instead of ps that access to data that are public, so no problems

  Point_s* p = &ps;  // I can have a pointer to a class
  p->x = 0.0;     // arrow operator
  p->print();

  auto& pr = ps;
  ++pr.x;
  pr.print();

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1;
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;
  as[3].x = 3;

  std::vector<Point_s> vs;
  vs.push_back(ps);
  vs[0].x = 999;
  ps.x = 11;
  ps.print();
  vs[0].print();

  return 0;
}
