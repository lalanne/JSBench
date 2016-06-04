
#include "benchmark/benchmark_api.h"

const int ITERATIONS = 1000000;

void fooImpl() {}

void foo(benchmark::State& state) {
    while (state.KeepRunning()) {
        fooImpl();
    }
}
BENCHMARK(foo);

BENCHMARK_MAIN();


