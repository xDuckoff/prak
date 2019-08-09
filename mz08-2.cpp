#include <iostream>

void skip_wc(char &c)
{
    do {
        if (!isspace(c)) {
            return;
        }
    } while(std::cin.get(c));

    exit(0);
}

void next(char &c)
{
    do {
        if (isspace(c)) {
            return;
        }
    } while(std::cin.get(c));

    exit(0);
}

void tmp_k(char &c, int &k)
{
    do {
        if (c != '0') {
            return;
        }
        ++k;
    } while(std::cin.get(c));

    std::cout << "0\n";
    exit(0);
}

void tmp_m(char &c, int &m)
{
    do {
        if (c != '1') {
            return;
        }
        ++m;
    } while(std::cin.get(c));

    std::cout << "1\n";
    exit(0);
}

void cnt_m(char&c, int &m, int corr)
{
    do {
        if (c != '1') {
            return;
        }
        ++m;
    } while(std::cin.get(c));

    if (m == corr) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }
    exit(0);
}

bool check(char &c, int k, int m)
{
    while (!isspace(c)) {
        int cur_k = 0;
        tmp_k(c, cur_k);
        if (cur_k != k) {
            return false;
        }

        int cur_m = 0;
        cnt_m(c, cur_m, m);
        if (cur_m != m) {
            return false;
        }
    }
    return true;
}

int main()
{
    char c = ' ';
    while (true) {
        skip_wc(c);

        int k = 0;
        tmp_k(c, k);

        int m = 0;
        tmp_m(c, m);

        if (k == 0 || m == 0) {
            std::cout << "0\n";
            next(c);
            continue;
        }

        if (check(c, k, m)) {
            std::cout << "1\n";
            next(c);
            continue;
        } else {
            std::cout << "0\n";
            next(c);
            continue;
        }
    }
}

