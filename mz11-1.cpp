#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> ans;

void gen_b(std::string &alp, std::string &s, int l, int k, int len)
{
    if (l == k) {
        std::string out;
        for (int i = 0; i < len - k; i++) {
            out.push_back(alp[i]);
        }

        for (int i = 0; i < len - k; i++) {
            out.push_back(alp[len - k - i - 1]);
        }

        for (int i = 0; i < k; i++) {
            out.push_back(s[i]);
        }

        for (int i = 0; i < k; i++) {
            out.push_back(s[k - i - 1]);
        }

        ans.push_back(out);
        return;
    }

    s[l] = '1';
    gen_b(alp, s, l + 1, k, len);
    s[l] = '2';
    gen_b(alp, s, l + 1, k, len); 
}

void gen_a(std::string &s, std::string &bet, int l, int k, int len)
{
    if (l == k) {
        gen_b(s, bet, 0, len - k, len);
        return;
    }

    gen_b(s, bet, 0, len - l, len);
    s[l] = '3';
    gen_a(s, bet, l + 1, k, len);
    s[l] = '4';
    gen_a(s, bet, l + 1, k, len); 
}

int main()
{
    int k;
    std::cin >> k;
    std::string alp(k / 2, ' '), bet(k / 2, ' ');

    gen_a(alp, bet, 0, k / 2, k / 2);

    std::sort(ans.begin(), ans.end());
    for (auto c : ans) {
        std::cout << c << "\n";
    }
}
