#include <iostream>

/*
 *      S -> B
 *      B -> 1B0 | 10A10
 *      A -> 0A1 | eps
 */

void A(std::string &in, size_t left, size_t right, std::string &out)
{
    if (left >= right) {
        out = "";
        return;
    } else {
        A(in, left + 1, right - 1, out);
        if (out.empty()) {
            out = "10";
        } else {
            out[out.size() / 2] = '1';
            out.append(2, '0');
        }
    }
}

void B(std::string &in, size_t left, size_t right, std::string &out)
{
    if (in[right] == '1' && in[left] == '0') {
        A(in, left, right, out);
    } else {
        B(in, left + 1, right - 1, out);
        out.push_back('0');
    }
}

int main()
{
    std::string s;
    std::string out;
    while (std::cin >> s) {
        B(s, 0, s.size() - 1, out);
        std::cout << out << "\n";
    }
}
