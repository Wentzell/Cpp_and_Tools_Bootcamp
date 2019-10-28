// -- lib.hpp

// Declare a function
int f(int m, int n);

// Declare a Class
struct A{
  int i;
  int j;
  int get_sum();
};

// An inline function
inline double short_f(double j) { return j * j; }

// A template functions
template<typename T>
bool greater_zero(T t) { return t > 0; }

// A template class
template<typename T>
struct templ_class {
  T t;
};