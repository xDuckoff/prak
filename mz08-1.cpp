#include <iostream>
#include <set>

using namespace std;

int check(string s)
{
    int border = 0;
    set<char> alph[2];
    alph[0].insert('3');
    alph[0].insert('4');
    alph[1].insert('1');
    alph[1].insert('2');
    if (s.size() == 0) {
        return 1;
    }

    for (auto c : s) {
        if (alph[border].find(c) == alph[border].end()) {
            border++;
            if (border <= 1 && alph[border].find(c) == alph[border].end()) {
                border++;
            }
        }

        if (border > 1) {
            return 0;
        }
    }
    return 1;   
}

int main()
{
    string s;
    while (cin >> s) {
        cout << check(s) << endl;
    }
}
