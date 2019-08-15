#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

constexpr int CNT = 3;
constexpr int ITER = 1000000;

std::mutex m;
double arr[CNT] = {};

void function(int n)
{
    for (int i = 0; i < ITER; i++) {
        m.lock();
        arr[n] += (n + 1) * 100;
        arr[(n + 1) % CNT] -= (n + 1) * 100 + 1;
        m.unlock();
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < CNT; i++) {
        threads.emplace_back(function, i);
    }

    for (auto &t : threads) {
        t.join();
    }

    for (double i : arr) {
        printf("%.10g\n", i);
    }
} 
