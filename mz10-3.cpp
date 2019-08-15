#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
    set<char> vis;
    vis.insert('S');
    
    vector< pair<char, string> > gram;
    string right;
    char left;
    int n = 0;

    while (cin >> left >> right) {
        gram.push_back(make_pair(left, right));
        if (vis.find(left) != vis.end()) {
            for (size_t i = 0; i < right.size(); i++) {
                if (right[i] >= 'A' && right[i] <= 'Z') {
                    vis.insert(right[i]);
                }
            }
        }
        n++;
    }

    bool ch = true;
    while (ch) {
        ch = false;
        for (int i = 0; i < n; i++) {
            left = gram[i].first;
            right = gram[i].second;
            if (vis.find(left) != vis.end()) {
                for (size_t i = 0; i < right.size(); i++) {
                    if (right[i] >= 'A' && right[i] <= 'Z') {
                        if (vis.find(right[i]) == vis.end()) {
                            vis.insert(right[i]);
                            ch = true;
                        }
                    }
                }
            }    
        }
    }

    for (int i = 0; i < n; i++) {
        char left = gram[i].first;
        string right = gram[i].second;
        if (vis.find(left) != vis.end()) {
            cout << left << ' ' << right << endl;
        }
    }    
}

