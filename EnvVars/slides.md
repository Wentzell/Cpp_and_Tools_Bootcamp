---
customTheme : "flatiron"
---

## Unix Environment Variables

* Local to each shell session
* Influence the way your system and software behaves


## Example `PATH`

A colon-separated list of directories (e.g. `/usr/bin`) searched for executable programs.

### How to get the value

`echo $PATH`

### How to set the value (prepending)

`export PATH=/home/user/bin:$PATH`

### See your full environment

`printenv`

### Permanently setting variables

Add the correpsonding lines to your `~/.bash_profile`


## Common environment variables

| Environment Variable | Brief Description                           |
| -------------------- | ------------------------------------------- |
| PATH                 | List of directories searched or executables |
| USER                 | The current username                        |
| HOME                 | Home directory of the current user          |
| PWD                  | Path to the current working directory       |


## Environment variables for software developement

| Environment Variable  | Brief Description                     |
| --------------------- | ------------------------------------- |
| CC / CXX              | The C/C++ compiler executable         |
| CFLAGS / CXXFLAGS     | Additional compiler flags for C/C++   |
| LDFLAGS               | Additional flags for the linker       |
| LIBRARY_PATH          | Directories searched for libraries at linktime |
| LD_LIBRARY_PATH       | Directories searched for dynamic libraries at runtime |
| CPATH                 | Directories searched for C/C++ header files (like -Idir) |
| CPLUS_INCLUDE_PATH    | Directories searched for C++ header files (like -isystem dir) |
| PYTHONPATH            | List of directories searched for python modules/packages |


## Environment variables affecting OpenMP

---
**Note**

These are of particular importance when using MPI + OpenMP.
Each MPI rank will usually spawn an equal number of OpenMP threads.
If you intend to use as many MPI ranks as cores are available you should `export OMP_NUM_THREADS=1`

---

| Environment Variable  | Brief Description                 |
| --------------------- | --------------------------------- |
| OMP_NUM_THREADS	    | Specifies globally the number of OpenMP threads to use |
| MKL_NUM_THREADS	    | Specifies the number of OpenMP threads to use only within the Intel MKL library |
| OPENBLAS_NUM_THREADS	| Specifies the number of OpenMP threads to use within the OpenBlas library |
            