#include <iostream>

/*
S -> AB
B -> 0B1 | 01
A -> aAX | aX
X0 -> 0X
X1 -> b1
Xb -> bb
 */

int main() {
    std::string s;
    while (std::cin >> s) {
        unsigned n = 0, m = 0;
        auto it = s.begin();
        while (it < s.end() && *it == 'a') {
            ++it;
            ++n;
        }
        while (it < s.end() && *it == '0') {
            ++it;
            ++m;
        }

        std::string check = std::string(n, 'a') + std::string(m, '0') + std::string(n, 'b') + std::string(m, '1');
        if (n > 0 && m > 0 && s == check) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
}
