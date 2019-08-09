#include <iostream>
#include <vector>

void gen(std::string &s, int l, bool f, int k)
{
    if (l == k) {
        std::cout << s << "\n";
        return;
    }

    if (!f) {
        s[l] = '1';
        gen(s, l + 1, true, k);
        s[l] = '2';
        gen(s, l + 1, true, k);
        s[l] = '3';
        gen(s, l + 1, false, k);
        s[l] = '4';
        gen(s, l + 1, false, k);
    } else {
        s[l] = '1';
        gen(s, l + 1, true, k);
        s[l] = '2';
        gen(s, l + 1, true, k);
    } 
}

int main()
{
    int k;
    std::cin >> k;
    std::string s(k, ' ');

    gen(s, 0, false, k);
}
