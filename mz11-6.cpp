#include <iostream>
#include <vector>
#include <map>


int main()
{
    std::vector<std::string> st;
    std::string s;
    std::map<std::string, int> qw;

    while (std::cin >> s) {
        if (*s.rbegin() == ':') {
            qw[std::string(s.begin(), s.end() - 1)] = st.size() + 1;
        } else {
            st.push_back(s);
        }
    }

    for (auto x : st) {
        if (qw.find(x) != qw.end()) {
            std::cout << qw[x]; 
        } else {
            std::cout << x;
        }
        std::cout << "\n";
    }
}
