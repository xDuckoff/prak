#include <iostream>
#include <vector>
#include <map>

constexpr int MAX_PR = 10;

struct Expression
{
private:
    std::string s;
    std::vector<bool> vis;
    std::map<char, int> priority;
public:
    explicit Expression(const std::string &s) : s(s), vis(std::vector<bool>(s.size(), true))
    {
        priority['*'] = priority['/'] = 1;
        priority['+'] = priority['-'] = 2;
        priority['&'] = 3;
        priority['^'] = 4;
        priority['|'] = 5;

    }
    int erase(size_t, size_t);
    void write();
};

int Expression::erase(size_t left, size_t right)
{
    int max_op = 0;
    int balance = 0;
    size_t ll = left;

    for (size_t i = left; i < right; ++i) {
        if (!balance && priority.find(s[i]) != priority.end()) {
            max_op = std::max(max_op, priority[s[i]]);
        } else if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            balance--;
        }
    }

    int prev = MAX_PR;
    int post;

    for (size_t i = left; i < right; ++i) {
        if (!balance && priority.find(s[i]) != priority.end()) {
            prev = priority[s[i]];
        }

        if (s[i] == '(') {
            if (!balance) {
                ll = i;
            }
            ++balance;
        } else if (s[i] == ')') {
            --balance;
            if (!balance) {
                auto in = erase(ll + 1, i);
                post = i + 1 < right ? priority[s[i + 1]] : MAX_PR;
                if (in < prev && in <= post) {
                    vis[ll] = vis[i] = false;
                    max_op = std::max(max_op, in);
                }
            }
        }
    }

    return max_op;
}

void Expression::write()
{
    for (size_t i = 0; i < s.size(); ++i) {
        if (vis[i]) {
            std::cout << s[i];
        }
    }
}

int main() {
    std::string s;
    std::cin >> s;

    Expression res(s);
    res.erase(0, s.size());
    res.write();
}
