---
customTheme : "flatiron"
---

### Important Compiler Flags (gcc/clang)

* `-g` -- Compile with debugging flags
* `-c` -- Compile only, do not link an executable
* `-o file` -- Output file
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
-Wshadow=local                  # GCC Only
-Wno-unused-but-set-parameter   # GCC Only
-Wshadow                        # Clang Only
-Wno-gcc-compat>                # Clang Only
```


## Header files and source files

| hpp                    | cpp                  |
|------------------------|----------------------|
| function declarations  | function definitions |
| class declarations     | class definitions    |
| inline functions       |                      |
| template functions     |                      |
| template classes       |                      |


## An Example

```cpp
// file.hpp

// Declare a function
int  f(int i, int j);

// Declare a Class
struct A;

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
// file.cpp

int f(int i, int j) { return i + j; }

struct A{
  int i;
  double j;
};
```