#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/////////// ALGORITHM TO IMPLEMENT ////////////////////

std::vector<int> find_traversal_order(std::vector<int> const & v)
{
    // Create the index vector 0, 1, 2, .. N
    std::vector<int> l(v.size());
    std::iota(begin(l), end(l), 0);
    
    // Custom-sort the index vector such that v[i] <= v[j]
    std::sort(begin(l), end(l), [&v](int i, int j){return v[i] < v[j];});

    return l;
}

////////////////////////////////////////////////////////


/////////// TEST CODE: MAKE IT PASS! ///////////////////

bool test1()
{
    auto v = std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 };
    auto expected = v;
    return find_traversal_order(v) == expected;
}

bool test2()
{
    auto v = std::vector<int>{ 3, 2, 1, 0, -1, -2 };
    auto expected = std::vector<int>{ 5, 4, 3, 2, 1, 0 };
    return find_traversal_order(v) == expected;
}

bool test3()
{
    auto v = std::vector<int>{ -2, 1, -1, 0, 2, 3, 5, 4 };
    auto expected = std::vector<int>{ 0, 2, 3, 1, 4, 5, 7, 6 };
    return find_traversal_order(v) == expected;
}

bool test4()
{
    auto v = std::vector<int>{ 1, 0, 0, 4, 3 };
    auto option1 = std::vector<int>{ 1, 2, 0, 4, 3 };
    auto option2 = std::vector<int>{ 2, 1, 0, 4, 3 };
    auto res = find_traversal_order(v);
    return res == option1 || res == option2;
}

int main()
{
    std::cout << "TEST 1: " << (test1() ? "PASSED" : "FAILED") << '\n';
    std::cout << "TEST 2: " << (test2() ? "PASSED" : "FAILED") << '\n';
    std::cout << "TEST 3: " << (test3() ? "PASSED" : "FAILED") << '\n';
    std::cout << "TEST 4: " << (test4() ? "PASSED" : "FAILED") << '\n';
}

////////////////////////////////////////////////////////

