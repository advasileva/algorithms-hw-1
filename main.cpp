#include <chrono>
#include <iostream>
#include <fstream>
#include "sorts/0-default.cpp"
#include "sorts/1-selection.cpp"
#include "sorts/2-bubble.cpp"
#include "sorts/3-bubble-iverson-1.cpp"
#include "sorts/4-bubble-iverson-2.cpp"
#include "sorts/5-insertion.cpp"
#include "sorts/6-bin-insertion.cpp"
#include "sorts/7-count.cpp"
#include "sorts/8-radix.cpp"
#include "sorts/9-merge.cpp"
#include "sorts/10-quick.cpp"
#include "sorts/11-heap.cpp"
#include "sorts/12-shell-ciura.cpp"
#include "sorts/13-shell.cpp"
#include "arrays.cpp"

/*
 * АиСД-2, 2023, задание 1
 * Васильева Алёна Дмитриевна БПИ218
 * IDE: Clion
 * Что-то сделано,
 * а что-то не сделано
 */

using namespace std;

int MEASURE_TIMES = 2;
std::string sort_name = "";
std::string array_name = "";
int array_size = 0;
char separator = ';';
std::ofstream results;
std::ofstream input;
std::ofstream output;

void record(int x) {
    results << sort_name << separator
        << array_name << separator
        << array_size << separator
        << x << "\n";
}

void print(int* arr, int n, std::ofstream *stream) {
    for (int i = 0; i < n; ++i) {
        *stream << arr[i] << ' ';
    }
    *stream << "\n";
}

void check(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            for (int i = 0; i < n; ++i) {
                std::cerr << arr[i] << ' ';
            }
            std::cerr << '\n';
            throw std::invalid_argument("sort " + sort_name + " incorrect");

        }
    }
}

long long evaluate(void (*func)(int *, int), int* arr, int n) {
    print(arr, n, &input);
    auto startTime = std::chrono::high_resolution_clock::now();

    func(arr, n);

    auto endTime = std::chrono::high_resolution_clock::now();

    auto timeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime
    ).count();
    print(arr, n, &output);
    check(arr, n);
    delete[] arr;
    return timeElapsed;
}


void iterateMeasureTimes(void (*func)(int *, int), int* arr, int n) {
    double sum = 0;
    for (int i = 0; i < MEASURE_TIMES; ++i) {
        sum += evaluate(func, copy(arr, n), n);
    }
    double avg = sum / MEASURE_TIMES;
    record(avg);
}

void iterateSizes(void (*func)(int *, int), int* arr) {
    for (int i = 100; i <= 4100; i += 100) {
        array_size = i;
        iterateMeasureTimes(func, arr, i);
    }
}

void iterateArraysTypes(void (*func)(int *, int)) {
    // Fix generation order
    pair<int* (*)(), const char *> arrays[] = {
            make_pair(small, "small"),
            make_pair(big, "big"),
    };
    for (auto & array : arrays) {
        array_name = array.second;
        iterateSizes(func, array.first());
    }
}

void iterateSorts() {
    pair<void (*)(int *, int), const char *> sorts[] = {
            make_pair(build_in, "build-in"),
            make_pair(selection, "selection"),
            make_pair(bubble, "bubble"),
            make_pair(bubbleIverson1, "bubble-iverson-1"),
            make_pair(bubbleIverson2, "bubble-iverson-2"),
            make_pair(insertion, "insertion"),
            make_pair(binInsertion, "bin insertion"),
            make_pair(counting, "counting"),
            make_pair(radix, "radix"),
            make_pair(mergeSort, "merge"),
            make_pair(quick, "quick"),
            make_pair(heap, "heap"),
            make_pair(shellCiura, "shell ciura"),
            make_pair(shell, "shell"),
    };
    for (auto & sort : sorts) {
        sort_name = sort.second;
        iterateArraysTypes(sort.first);
    }
}

int main() {
    results.open("../test.csv");
    input.open("../input.txt", std::ios_base::beg);
    output.open("../output.txt", std::ios_base::beg);
    iterateSorts();
    return 0;
}
