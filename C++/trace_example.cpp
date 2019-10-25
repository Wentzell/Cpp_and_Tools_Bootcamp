// g++-9 -std=c++17 -fconcepts trace_example.cpp -fsanitize=address -O3

#include <iostream>
#include <vector>

// With concept TS (slight change for C++20).
template <typename T> concept bool Matrix = requires(T m) {
  { m(0, 0) }
  ->double; // std::convertible_to<double>;
  { dim(m) }
  ->int; // std::convertible_to<int>;
};

//  trace function
template <Matrix M> double trace(M const &m) {
  double r = 0;
  int d = dim(m); // size of the matrix d x d
  for (int i = 0; i < d; ++i)
    r += m(i, i);
  return r;
}

// baby matrix class
class square_matrix {
  int n;
  std::vector<double> data;

public:
  square_matrix(int n) : n(n), data(n * n, 1) {}

  double operator()(int i, int j) const { return data[i + n * j]; }
  friend int dim(square_matrix const &m) { return m.n; }

  // Access to modify the matrix : not required by Matrix
  double &operator()(int i, int j) { return data[i + n * j]; }
};

// lazy addition
template <typename A, typename B> struct lazy_addition {
  A const &a;
  B const &b;
  double operator()(int i, int j) const { return a(i, j) + b(i, j); }
  friend int dim(lazy_addition const &x) { return dim(x.a); }
};

// implement a + b
template <Matrix A, Matrix B>
lazy_addition<A, B> operator+(A const &a, B const &b) {
  return {a, b};
}

// ----  Other matrix classes  ------

struct hilbert_matrix {
  int n;

  double operator()(int i, int j) const { return 1.0 / (i + j + 1); }
  friend int dim(hilbert_matrix const &m) { return m.n; }
};

// -----------

class rank1_matrix {
  std::vector<double> x, y; // a place to store the data

public:
  rank1_matrix(std::vector<double> x, std::vector<double> y) : x(x), y(y) {}

  double operator()(int i, int j) const { return x[i] * y[j]; }
  friend int dim(rank1_matrix const &m) { return m.x.size(); }
};

// ------------------------

// main code

int main() {

  auto m1 = square_matrix{4};
  auto m2 = hilbert_matrix{4};
  auto m3 = rank1_matrix{{0, 1, 2, 3}, {1, 1, 1, 1}};

  std::cout << trace(m1) << '\n'
            << trace(m1 + m2) << '\n'
            << trace(m1 + m3) << std::endl;
}
