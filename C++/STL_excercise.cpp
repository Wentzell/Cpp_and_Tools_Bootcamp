#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/////////// ALGORITHM TO IMPLEMENT ////////////////////

std::vector<int> find_traversal_order(std::vector<int> const &v) {

  // Given a vector of integers (v_0 , ... , v_n),
  // generate a vector of indices (l_0, ... ,l_n) that
  // label the elements from smallest to largest, i.e.
  // v_{l_i} ≤ v_{l_{i+1}} ∀i ∈ {0,...,

  // Solve your problem below using STL algorithms
  // ...
  return {};
}

////////////////////////////////////////////////////////

/////////// TEST CODE: MAKE IT PASS! ///////////////////

bool test1() {
  auto v = std::vector<int>{0, 1, 2, 3, 4, 5, 6};
  auto expected = v;
  return find_traversal_order(v) == expected;
}

bool test2() {
  auto v = std::vector<int>{3, 2, 1, 0, -1, -2};
  auto expected = std::vector<int>{5, 4, 3, 2, 1, 0};
  return find_traversal_order(v) == expected;
}

bool test3() {
  auto v = std::vector<int>{-2, 1, -1, 0, 2, 3, 5, 4};
  auto expected = std::vector<int>{0, 2, 3, 1, 4, 5, 7, 6};
  return find_traversal_order(v) == expected;
}

bool test4() {
  auto v = std::vector<int>{1, 0, 0, 4, 3};
  auto option1 = std::vector<int>{1, 2, 0, 4, 3};
  auto option2 = std::vector<int>{2, 1, 0, 4, 3};
  auto res = find_traversal_order(v);
  return res == option1 || res == option2;
}

int main() {
  std::cout << "TEST 1: " << (test1() ? "PASSED" : "FAILED") << '\n';
  std::cout << "TEST 2: " << (test2() ? "PASSED" : "FAILED") << '\n';
  std::cout << "TEST 3: " << (test3() ? "PASSED" : "FAILED") << '\n';
  std::cout << "TEST 4: " << (test4() ? "PASSED" : "FAILED") << '\n';
}

////////////////////////////////////////////////////////
