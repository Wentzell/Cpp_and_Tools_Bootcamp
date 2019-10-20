#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<long> random_vec(size_t s, long l, long r) {
  auto rng = [eng = std::mt19937{}, dist = std::uniform_int_distribution<long>{
                                        l, r}]() mutable { return dist(eng); };
  auto v = std::vector<long>(s);
  std::generate(begin(v), end(v), rng);
  return v;
}

bool task1(long N) {
  std::cout << "task1" << std::endl;
  auto v = random_vec(N, 0, N);
  auto is_nonzero = [](long i) { return i != 0; };
  return std::all_of(begin(v), end(v), is_nonzero);
}

bool task2(long N) {
  std::cout << "task2" << std::endl;
  auto v = random_vec(N, 0, N);
  auto is_zero = [](long i) { return i == 0; };
  return std::any_of(begin(v), end(v), is_zero);
}

bool run_calculation() { return task1(1e8) && task2(1e8); }

int main() {
  std::cout << "start" << std::endl;
  bool result = run_calculation();
  std::cout << "done with result " << result << std::endl;
  return 0;
}
