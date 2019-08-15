
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

struct Account
{
    double money;
    std::mutex m;
    Account() : money(0.0), m() {}
};

void change(uint32_t iter, Account &acc1, double dif1, Account &acc2, double dif2)
{
    for (uint32_t i = 0; i < iter; ++i) {
        std::scoped_lock lock(acc1.m, acc2.m);
        acc1.money += dif1;
        acc2.money += dif2;
    }
}

int main() {
    uint32_t acc_count, thr_count;
    std::cin >> acc_count >> thr_count;
    std::vector<Account> accounts(acc_count);

    std::vector<std::thread> threads;


    for (uint32_t i = 0; i < thr_count; ++i) {
        uint32_t iter, id1, id2;
        double dif1, dif2;
        std::cin >> iter >> id1 >> dif1 >> id2 >> dif2;
        if (id1 < id2) {
            threads.emplace_back(change, iter, std::ref(accounts[id1]), dif1, std::ref(accounts[id2]), dif2);
        } else {
            threads.emplace_back(change, iter, std::ref(accounts[id2]), dif2, std::ref(accounts[id1]), dif1);
        }
    }

    for (auto &t : threads) {
        t.join();
    }

    for (auto &a : accounts) {
        printf("%.10g\n", a.money);
    }
}
