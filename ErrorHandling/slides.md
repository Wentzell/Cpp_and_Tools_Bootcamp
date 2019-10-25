---
customTheme : "flatiron"
---

## Exceptions

```cpp
#include <exception>

auto do_something(){
    // do_some_work
    if( ... )
      throw std::exception("Describe what went wrong");
    // ...
}

int main(){
  // ...
  try {
    do_something(); 
  }
  catch (std::exception const & e) {
    cout << e.what();
    // handle the problem ...
  }
}
```


### Use exceptions for **exceptional** behavior that you can **recover** from!

```cpp
// ...
try {
  file = open_file("myfile"); 
  val = read_value(file);
}
catch (std::exception const & e) {
  cout << e.what();
  val = default;
}
// ...
```

Use ```std::terminate()```
with an error message for unrecoverable errors.


### Check your pre- and postconditions

```cpp
MyContainer{
    // ...
    int & operator[](int idx){
        EXPECTS(is_within_boundrary(idx)); // Precondition
        return _data[idx];
    }
    // ...

    value get_value(){ 
        value v;
        // do some calculation ...
        ENSURES(property(v)); // Postcondition
        return v;
    }
};
```


### Check your invariants

**Invariant**: A conditions that must be true at some point in time or even always while your program is executing. 

```cpp
MyContainer{
    // ...
    bool check_invariants(){
        // ... 
    }
    // ...
    value get_value(){ 
        EXPECTS(check_invariants());
        value v;
        // do some calculation ...
        ENSURES(property(v)); // Postcondition
        return v;
    }
};
```


### EXPECTS

```cpp
#ifdef TRIQS_DEBUG
#define EXPECTS(X) \
  if (!(X)) { \
    std::cerr << "Precondition " << AS_STRING(X) \
              << " violated at " << __FILE__     \
              << ":" << __LINE__ << "\n" <<      \
              triqs::utility::stack_trace();     \ 
              std::terminate();                  \
  }
#elif
#define EXPECTS(X)
#endif
```


### ENSURES

```cpp
#ifdef TRIQS_DEBUG
#define ENSURES(X) \
  if (!(X)) { \
    std::cerr << "Postcondition " << AS_STRING(X) \
              << " violated at " << __FILE__      \
              << ":" << __LINE__ << "\n" <<       \
              triqs::utility::stack_trace();      \ 
              std::terminate();                   \
  }
#elif
#define ENSURES(X)
#endif
```


### ASSERT

```cpp
#ifdef TRIQS_DEBUG
#define ASSERT(X) \
  if (!(X)) { \
    std::cerr << "Assertion " << AS_STRING(X)     \
              << " violated at " << __FILE__      \
              << ":" << __LINE__ << "\n" <<       \
              triqs::utility::stack_trace();      \ 
              std::terminate();                   \
  }
#elif
#define ASSERT(X)
#endif
```