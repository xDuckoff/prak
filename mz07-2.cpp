#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    int cnt = 0;
    size_t first = s.size();
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ++cnt;
            first = std::min(i, first);
        }
    }

    if (cnt & 1) {
        s[first] = '0';
    }

    std::cout << s;
}
