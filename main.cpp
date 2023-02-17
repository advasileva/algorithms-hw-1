#include <chrono>
#include <iostream>
#include "sorts/0-default.cpp"
#include "arrays.cpp"

/*
 * АиСД-2, 2023, задание 1
 * Васильева Алёна Дмитриевна БПИ218
 * IDE: Clion
 * Что-то сделано,
 * а что-то не сделано
 */

using namespace std;

int MEASURE_TIMES = 10;

void record(int x, std::string name) {
    std::cout << name << ';' << x << "\n";
}

long long evaluate(void (*func)(int *, int), int* arr, int n) {
    auto startTime = std::chrono::high_resolution_clock::now();

    func(arr, n);

    auto endTime = std::chrono::high_resolution_clock::now();

    auto timeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime
    ).count();
    return timeElapsed;
}


void iterateMeasureTimes(void (*func)(int *, int), int* arr, int n, std::string name) {
    double sum = 0;
    for (int i = 0; i < MEASURE_TIMES; ++i) {
        sum += evaluate(func, copy(arr, n), n);
    }
    double avg = sum / MEASURE_TIMES;
    record(avg, name);
}

void iterateSizes(void (*func)(int *, int), int* arr, std::string name) {
    for (int i = 50; i < 300; i += 50) {
        iterateMeasureTimes(func, arr, i, name + ';' + std::to_string(i));
    }
}

void iterateArraysTypes(void (*func)(int *, int), std::string name) {
    pair<int* (*)(), const char *> arrays[] = {
            make_pair(stupid, "default")
    };
    for (auto & array : arrays) {
        iterateSizes(func, array.first(), name + ';' + array.second);
    }
}

void iterateSorts() {
    pair<void (*)(int *, int), const char *> sorts[] = {
            make_pair(default0, "default")
    };
    for (auto & sort : sorts) {
        iterateArraysTypes(sort.first, sort.second);
    }
}

int main() {
    iterateSorts();
    return 0;
}
