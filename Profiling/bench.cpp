#include <iostream>
#include <vector>

long sum_of_squares(long N) {
  std::cout << "squares" << std::endl;
  long res = 0;
  for (int i = 1; i < N; ++i) {
    res += i * i;
  }
  return res;
}

long sum_of_cubes(long N) {
  std::cout << "cubes" << std::endl;
  long res = 0;
  for (int i = 1; i < N; ++i) {
    res += i * i * i;
  }
  return res;
}

long run_calculation() { return sum_of_squares(1e10) + sum_of_cubes(1e10); }

int main() {
  std::cout << "start" << std::endl;
  long result = run_calculation();
  std::cout << "done with result " << result << std::endl;
  return 0;
}
