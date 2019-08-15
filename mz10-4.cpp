#include <iostream>
#include <map>
#include <set>

using Mypair = std::pair<std::string, std::string>;

int main()
{
    std::string CUR, NEW, CHAR;
    std::map<Mypair, std::string> st_table;
    std::set<std::string> end_st;

    std::cin >> CUR;
    while (CUR != "END") {
        std::cin >> CHAR >> NEW;
        st_table[Mypair(CUR, CHAR)] = NEW;
        std::cin >> CUR;
    }

    std::cin >> CUR;
    while (CUR != "END") {
        end_st.insert(CUR);
        std::cin >> CUR;
    }

    std::string state;
    std::cin >> state;

    std::string s;
    std::cin >> s;

    for (size_t i = 0; i < s.size(); ++i) {
        auto v = Mypair(state, std::string(1, s[i]));
        if (st_table.find(Mypair(v)) == st_table.end()) {
            std::cout << 0 << "\n" << i << "\n" << state << "\n";
            return 0;
        }
        state = st_table[v];
    }

    if (end_st.find(state) == end_st.end()) {
        std::cout << 0 << "\n" << s.size() << "\n" << state << "\n";
        return 0;
    }

    std::cout << 1 << "\n" << s.size() << "\n" << state << "\n";
}
