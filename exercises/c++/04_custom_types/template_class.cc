#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  ~Vector() { delete[] elem; }
  
  auto size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }

  const num& operator[](const std::size_t i) const { return elem[i]; }
  
  // to implement the range based for loops (boundary checking)
  num* begin() {return &elem[0];}
  num* end() {return &elem[_size];}
};

template <typename T>
auto& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i]=i
      
  Vector<double>* pv{&v};

  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  Vector<double>& rv{v};

  rv[5] = 555;

  for (auto x : v)
     std::cout << x << std::endl;

  return 0;
}