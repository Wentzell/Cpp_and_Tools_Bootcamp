---
customTheme : "flatiron"
---

## Documentation Generation

[Cpp2Rst - github.com/TRIQS/cpp2py](https://github.com/TRIQS/cpp2py)


## Format of Documentation Strings

```c++
namespace NS {
  /**
   * A brief description
   *
   * @tparam T  Doc of template parameter
   * @param t   Doc of parameter
   * @return    Doc of returned value
   *
   * @example ex.cpp
   */
  template <typename T>
  T func(T t) {
    return t;
  }

  /**
   * A brief description
   *
   * A more detailed description
   *
   * @tparam T  Doc of template parameter
   *
   * @example ex.cpp
   */
  template <typename T>
  struct cls {

    /// A default constructor
    cls(){}

    /// A public member
    int member;

    /// A public member function
    void func(){}
  };

} // namespace NS
```

* Full example in `doc.cpp`
* Generation of rst-based API website


## Valid Function Documentation Tags

* `@include file` ---  File to include [default: the definition file]
* `@head text` --- Head of longer description
* `@tail text` --- Tail of longer description`
* `@figure file: text` --- Optional illustration
* `@tparam T text` --- Doc of template parameter
* `@param t text` --- Doc of parameter
* `@return text` --- Doc of returned value
* `@warning text` Optional Warning


## Valid Class Documentation Tags

* `@include file` ---  File to include [default: the definition file]
* `@tparam T text` --- Doc of template parameter
* `@note text` Optional Note
* `@warning text` Optional Warning
* `@figure file: text` --- Optional illustration

note: c++2rst doc.cpp -N NS -o doc
      sphinx-build doc html