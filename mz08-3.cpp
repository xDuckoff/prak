#include <iostream>

int main()
{
    std::string left, right;
    int cnt_rules = 0;
    bool empty = false;
    bool ks = true;
    bool start = false;
    bool wrong = false;

    while (std::cin >> left >> right) {
        cnt_rules++;

        int n = 0;
        for (auto c : left) {
            if (c >= 'A' && c <= 'Z') {
                ++n;
            }
        }

        if (!n) {
            wrong = true;
        }

        if (left == "S") {
            start = true;
        }

        if (left.size() > 1 || n != 1) {
            ks = false;
        }

        if (right == "_") {
            empty = true;
        }
    }

    if (cnt_rules == 0 || !start || wrong) {
        std::cout << -1 << "\n";
    } else if (ks) {
        std::cout << 2;
        if (!empty) {
            std::cout << 3;
        }
        std::cout << "\n";
    } else {
        std::cout << "10\n";
    }
}
