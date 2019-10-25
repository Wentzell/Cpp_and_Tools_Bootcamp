---
customTheme : "flatiron"
---

# CMake & <br> App4Triqs

### Philipp T. Dumitrescu



## Fast & Reliable Development

* Get *code ideas* into *science results* 
* Requirements: Easy, Fast, Reliable, Portable
* **Solution: Have other people deal with this** <br> [e.g. consumer software, conda python]
* Problem: We accept generic use-cases / choices
    - Loose a huge amount of information about our code
    - Loose the ability to plug-into many tools
    - Hard to optimize to peak performance
    - Restrict ability to develop new directions


## Simple Builds

* Steps: preprocessing, compiling, assembling and linking
* Simple example:

```bash
clang++ -DMY_FLAG -o hello_world -I include src/main.cpp 
```

* The same in real life:

```bash
clang++ -I ~/googletest/include -I ~/googletest -Wall -Wshadow -Werror 
-W -Wconversion -DGTEST_HAS_PTHREAD=1 -fexceptions -Wpointer-arith
-Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch -Wunused-parameter
-Wcast-alig -Wchar-subscripts -Winline -Wredundant-decls 
-o gtest-all.cc.o -c ~/googletest/src/gtest-all.cc
```

* Now do this for 203 .cpp files of TRIQS ... and link




## CMake

* A simple **programming language** to specify build logic
* **Not** itself a build system: <br>
"build system builder" / "makefile maker"
* Problems it addresses:
  - Manage dependencies
  - Manage compile options and output of program
  - Work on different platforms & hardware
  - Integrate with tests & continuous integration (CI)
  - Scaling to large projects
* For you: Most of the work has been done in **App4Triqs**!


## CMake

* Idea: break up build into **modules** / **targets**
* A simple ``CMakeLists.txt`` file in top-level-folder:

```cmake
cmake_minimum_required(VERSION 3.12)
project(my_hello_world VERSION 1.0.0 LANGUAGES C CXX)

add_executable(hello_world src/main.cpp)
target_include_directories(hello_world PUBLIC include)
if (ADD_MY_FLAG)
   target_compile_definitions(hello_world PRIVATE MY_FLAG)
endif()
````

* We build cmake (out-of-source) by invoking

```bash
cmake ../path_to_project_folder
```


## CMake: Finding Packages

```cmake
find_package(TRIQS 2.2 REQUIRED)
find_package(GSL REQUIRED)

target_link_libraries(hello_world PUBLIC triqs PRIVATE GSL::gsl)
```

* Here ```triqs``` and ```GSL::gsl``` are also targets and set correct flags, include directories, libraries to link, etc.
* Here ```PUBLIC``` and ```PRIVATE``` keywords specify how this information gets propagated (also ```INTERFACE```)
* ``find_package`` exists for many common libraries <br>
any cmake project you write can easily support this


## Basic CMake Building Blocks

* Power comes in complex tasks & platform independence 
*  **Philosophy**: code using targets ["Modern CMake"]

`add_executable()`, `add_library()`

```cmake
get_target_property(), set_target_properties(),
target_compile_definitions(), target_compile_features(),
target_compile_options(), target_include_directories(), 
target_link_libraries(), target_sources()
```
* Don't set options by hand / hardcode. Declare intent:
```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
```


## Relate your code to others

* CMake knows how your all of your code fits together
* Support for tools:  
  - Testing: googletest, 
  - Code Analysis: clang-tidy, cpplint, include-what-you-use, link-what-you-use, clazy
  - Debugging: sanitizers, ...
  - IDEs & Language servers: `compile_commands.json` (but note cases with single header files)
  - Packaging: debian packages
  - ...
* Automate all of this!



## App4Triqs

* Skeleton project applications from Nils (& friends)
* Everything should work "out of the box"
* Features: 
  - Full c++ build system
  - c++ warpping into python (using cpp2py)
  - Sanitizers & Checks, including for wrapped python
  - Documentation
  - CI template (Travis / Jenkins) 
  - Packaging (Docker & Debian packages)
* Allows scalability of infrastructure updates


## Demonstration

* Look at cmake structure


## Hands-On

* Website: https://github.com/TRIQS/app4triqs

* Different branches: `2.2.x`, `unstable`, `notriqs`, ...

**Task: download app4triqs, set-up project and compile with clang.<br> Add a new dependancy (e.g. `gsl`, `protobuf`)**


```txt
https://github.com/Wentzell/Cpp_and_Tools_Bootcamp/blob/master/Cpp2Py/slides.md
Install compdb. E.g. ```pip install compdb```
```

```bash
# In a new folder. Make app4triqs project:
git clone https://github.com/triqs/app4triqs --branch notriqs cppbootcamp
cd cppbootcamp
./share/squash_history.sh
./share/replace_and_rename.sh cppbootcamp
git add -A && git commit -m "Adjust app4triqs skeleton for cppbootcamp"
# Build
cd ..; mkdir build; cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_INSTALL_PREFIX=$PWD/../cppbootcamp.bin ../cppbootcamp
# Make
make -j8
make test
# Set up file for clangd
cd ../cppbootcamp
compdb -p ../build/ list > compile_commands.json
```
(vscode-clangd. Arguments -clang-tidy, -background-index)



## Resources 

* Daniel Pfeifer. *Effective CMake* (https://www.youtube.com/watch?v=bsXLMQ6WgIk)
* Mathieu Ropert. *Modern CMake for modular design* (https://www.youtube.com/watch?v=eC9-iRN2b04)


