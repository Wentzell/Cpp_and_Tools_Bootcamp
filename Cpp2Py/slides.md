---
customTheme : "flatiron"
---

## Interfacing C++ and Python

[Cpp2Py - github.com/TRIQS/cpp2py](https://github.com/TRIQS/cpp2py)


### Setup

```bash
$ git clone https://github.com/TRIQS/cpp2py cpp2py.src
$ mkdir cpp2py.build && cd cpp2py.build
$ cmake ../cpp2py.src -DCMAKE_INSTALL_PREFIX=path_to_install
$ make install
```


### A simple Example --- `simple.hpp`
```cpp
/// A very useful class
struct myclass {
  int a = 39, b = 3;

  /// The the sum of all members
  int get_sum() const { return a + b; }
};
```

Just run c++2py on the source file
```bash
$ c++2py simple.hpp
Welcome to C++2py
Parsing the C++ file (may take a few seconds) ...
... done.

Analysing dependencies
Wrapping classes:
    myclass
Generating simple_desc.py
```


### The descriptor file --- `simple_desc.py`

```python
# Generated automatically using the command :
# c++2py simple.hpp
from cpp2py.wrap_generator import *

# The module
module = module_(full_name = "simple", doc = r"", app_name = "simple")

# Imports

# Add here all includes
module.add_include("simple.hpp")

# Add here anything to add in the C++ code at the start, e.g. namespace using
module.add_preamble("""

""")

# The class myclass
c = class_(
        py_type = "Myclass",  # name of the python class
        c_type = "myclass",   # name of the C++ class
        doc = r"""A Simple class""",   # doc of the C++ class
        hdf5 = False,
)

c.add_member(c_name = "a",
             c_type = "int",
             read_only= False,
             doc = r"""""")

c.add_member(c_name = "b",
             c_type = "int",
             read_only= False,
             doc = r"""""")

c.add_method("""int get_sum ()""",
             doc = r"""The the sum of all members""")

module.add_class(c)

module.generate_code()
```


### Compile the module

```bash
$ python simple_desc.py simple_wrap.hxx
$ g++ -shared -o simple.so -lcpp2py -lpython2.7
```

### Import and use

```python
from simple import Myclass
print Myclass().get_sum()

----- Output ------
42
```


### Some useful options (c.f. `c++2py --help`)

* `--target_file_only` --- No recursion into includes
* `-N mynamespace` --- Filter by Namespace
* `-I somedir` --- Add include directories
* `--cxxflags "flags"` --- Add compile flags
* `-r my_desc.py` --- Regenerate a file


## Real-World Examples

* [app4triqs Skeleton --- github.com/triqs/app4triqs](https://github.com/triqs/app4triqs)
* [TRIQS CTHyb --- triqs.github.io/cthyb](https://triqs.github.io/cthyb/2.1.x/guide/aim.html)
* [IPython Cell Magic --- triqs.github.io/notebook](https://triqs.github.io/notebook)

note: head app4triqs/python/app4triqs_module_desc.py
      c++2py -r  app4triqs_module_desc.py