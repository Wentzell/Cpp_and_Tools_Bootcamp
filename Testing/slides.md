---
customTheme : "flatiron"
---

## Google Test
https://github.com/google/googletest

### A testing framework by Google


## A simple example

```cpp
#include <gtest/gtest.h>

TEST(Test_Group, Test1) {
  // XXX Do something
  // EXPECT_TRUE( .. );
  // EXPECT_FALSE( .. );
  // EXPECT_EQ( .. ); // a == b
  // EXPECT_NE( .. ); // a != b
  // EXPECT_LT( .. ); // a < b
  // EXPECT_LE( .. ); // a <= b
  // EXPECT_GT( .. ); // a > b
  // EXPECT_GE( .. ); // a >= b
}

TEST(Test_Group, Test2) {
  // XXX Do something
}
```


## Compiling the test

`g++  test.cpp -lgtest -lgtest_main`



## The test output

```
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from Test_Group
[ RUN      ] Test_Group.Test1
[       OK ] Test_Group.Test1 (0 ms)
[ RUN      ] Test_Group.Test2
[       OK ] Test_Group.Test2 (0 ms)
[----------] 2 tests from Test_Group (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 2 tests.
```


## The test output on failure

```
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from Test_Group
[ RUN      ] Test_Group.Test1
test.cpp:4: Failure
Value of: false
  Actual: false
Expected: true
[  FAILED  ] Test_Group.Test1 (0 ms)
[ RUN      ] Test_Group.Test2
[       OK ] Test_Group.Test2 (0 ms)
[----------] 2 tests from Test_Group (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] Test_Group.Test1

 1 FAILED TEST
 ```


## Testing and App4Triqs
https://github.com/TRIQS/app4triqs

* Simply add your test sources to the `test/c++` directory
* Configure and build your project as before
* Run the tests with `make test` or `ctest`


## Resources

 * github.com/google/googletest
 * github.com/TRIQS/app4triqs
 * triqs.github.io/app4triqs/unstable/install.html