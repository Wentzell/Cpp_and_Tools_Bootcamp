---
customTheme : "flatiron"
---

### Important Compiler Flags (gcc/clang)

* `-g` -- Compile with debugging flags
* `-c` -- Compile only, do not link an executable
* `-o file` -- Output file
* `-Idir` -- Search headers in dir
* `-Ldir` -- Search libraries in dir
* `-Wall -Wextra -Wpedantic` -- Turn on compiler warnings
* `-std=c++17` -- Set the C++ Standard to use
* `-stdlib=libc++` -- Choose the clang stdlib implementation
* `-stdlib=libstdc++` -- Choose the gnu stdlib implementation
* `-O1 -O2 -O3` -- Optimization level
* `-march=native` -- Use architecture specific optimizations
* `-Ofast` -- Use **unsafe** optimizations


## Our choice of compiler warnings

```
-Wall
-Wextra
-Wpedantic
-Wno-sign-compare
-Wshadow=local                  # GCC
-Wno-unused-but-set-parameter   # GCC
-Wshadow                        # Clang
-Wno-gcc-compat>                # Clang
```


## Header files and source files

| hpp                    | cpp                  |
|------------------------|----------------------|
| function declarations  | function definitions |
| class declarations     | class definitions    |
| inline functions       |                      |
| template functions     |                      |
| template classes       |                      |


## An Example Library

```cpp
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
```

```cpp
// -- lib.cpp
# include "lib.hpp"

int f(int m, int n) { return m - n; }

int A::get_sum() { return i + j; } 
```


## The user
```cpp
#include "lib.hpp"

int main(){
  int m = 0;
  A a = A{1, 2};
  greater_zero(a.i);
  return f(m, a.i);
}
```