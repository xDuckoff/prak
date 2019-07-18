#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s) {
        for (size_t i = 0; i < s.size(); i++) {
            string c_s = s.substr(i, s.size() - i);
            string p_s = c_s;
            reverse(c_s.begin(), c_s.end());
            if (c_s == p_s) {
                cout << c_s << endl;
                break;
            }
        }
    }
}
