#include <iostream>
#include <map>
#include <set>
#include <queue>

using Mypair = std::pair<std::string, std::string>;
using Vpair = std::pair<std::string, int>;

int main()
{
    std::string CUR, NEW, CHAR;
    std::map<std::string, std::vector<Mypair>> st_table;
    std::map<std::string, std::vector<std::string>> eps;

    std::set<std::string> end_st;

    std::cin >> CUR;
    while (CUR != "END") {
        std::cin >> CHAR >> NEW;
        if (CHAR != "eps") {
            st_table[CUR].push_back(Mypair(CHAR, NEW));
        } else {
            eps[CUR].push_back(NEW);
        }
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

    std::queue<Vpair> q;
    std::set<Vpair> vis;
    q.push(Vpair(state, 0));

    int cnt = 0;
    while (!q.empty()) {
        Vpair cur_v = q.front();
        q.pop();
        if (vis.find(cur_v) != vis.end()) {
            continue;
        }

        vis.insert(cur_v);
        cnt = std::max(cnt, cur_v.second);

        auto ch = eps[cur_v.first];
        for (auto &to : ch) {
            q.push(Vpair(to, cur_v.second));
        }

        if (cur_v.second < static_cast<int>(s.size())) {
            auto es = st_table[cur_v.first];
            for (auto &to : es) {
                if (std::string(1, s[cur_v.second]) == to.first) {
                    q.push(Vpair(to.second, cur_v.second + 1));
                }
            }
        } else if (end_st.find(cur_v.first) != end_st.end()){
            std::cout << 1 << "\n" << s.size() << "\n";
            return 0;
        }
    }

    std::cout << 0 << "\n" << cnt << "\n";
}
