
#include "benchmark/benchmark_api.h"
#include "jsapi.h"
#include "js/Initialization.h"

using namespace JS;

const int ITERATIONS = 1000000;

void fooImpl() {
    JS_Init();
}

void foo(benchmark::State& state) {
    while (state.KeepRunning()) {
        fooImpl();
    }
}
BENCHMARK(foo);

BENCHMARK_MAIN();


