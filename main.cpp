
#include "benchmark/benchmark_api.h"
#include "jsapi.h"
#include "js/Initialization.h"

using namespace JS;

const int ITERATIONS = 1000000;

int fooImpl() {
    // Initialize the JS engine.
    if (!JS_Init()) return 1;

    // Create a JS runtime.
    JSRuntime *rt = JS_NewRuntime(8L * 1024L * 1024L);
    if (!rt) return 1;
}

void foo(benchmark::State& state) {
    while (state.KeepRunning()) {
        fooImpl();
    }
}
BENCHMARK(foo);

BENCHMARK_MAIN();


