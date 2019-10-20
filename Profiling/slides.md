---
customTheme : "flatiron"
---

## Google Perftools 
https://github.com/gperftools/gperftools

* Command line tools for easy CPU and Heap profiling
* 


## A simple example

```cpp
#include <iostream>
#include <vector>

long sum_of_squares(long N) {
  std::cout << "squares" << std::endl;
  long res = 0;
  for (int i = 1; i < N; ++i) {
    res += i * i;
  }
  return res;
}

long sum_of_cubes(long N) {
  std::cout << "cubes" << std::endl;
  long res = 0;
  for (int i = 1; i < N; ++i) {
    res += i * i * i;
  }
  return res;
}

long run_calculation() { return sum_of_squares(1e10) + sum_of_cubes(1e10); }

int main() {
  std::cout << "start" << std::endl;
  long result = run_calculation();
  std::cout << "done with result " << result << std::endl;
  return 0;
}
```


## Profiling Steps

1. Compile with optimization and debugging flags

`g++ -O3 -g bench.cpp -o bench`

2. Generate the profiling data

`LD_PRELOAD=$HOME/opt/gperftools/lib/libprofiler.so CPUPROFILE=bench.prof ./bench`

2. Analyze the profiling data, e.g.

`pprof --text bench bench.prof`

```
Total: 951 samples
     549  57.7%  57.7%      549  57.7% sum_of_cubes
     402  42.3% 100.0%      402  42.3% sum_of_squares
       0   0.0% 100.0%      951 100.0% __libc_start_main
       0   0.0% 100.0%      951 100.0% _start
       0   0.0% 100.0%      951 100.0% main
       0   0.0% 100.0%      951 100.0% run_calculation (inline)
```


## Callgraph

`pprof --svg bench bench.prof > bench.prof.svg`

![Example Output](./bench.prof.svg)


## Flamegraph
`pprof --collapsed bench bench.prof | ./flamegraph.pl - > bench.prof.flamegraph.svg`

![Example Output](./bench.prof.flamegraph.svg)


## Resources

* https://github.com/gperftools/gperftools
* https://github.com/brendangregg/FlameGraph