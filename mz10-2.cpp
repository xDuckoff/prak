#include <iostream>
#include <vector>

void gen(int k, int n)
{
    if (n == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "a";
    }

    for (int i = 0; i < k / 2 - n; i++) {
        std::cout << "b";
    }

    for (int i = 0; i < k / 2 - n; i++) {
        std::cout << "c";
    }

    for (int i = 0; i < n; i++) {
        std::cout << "d";
    }

    std::cout << std::endl;
    gen(k, n - 1);
}

int main()
{
    int k;
    std::cin >> k;
    if (k == 0 || k % 2) {
        return 0;
    }

    gen(k, k / 2 - 1);
}
