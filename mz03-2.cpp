#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void process(const vector<int> &in, vector<int> &out)
{
    vector<int> copy = in;
    sort(copy.begin(), copy.end());
    auto last = unique(copy.begin(), copy.end());

    int cnt = 0;
    auto x = copy.begin();
    for ( ; x < last && (*x) < 0; ++x);
    if (x == last) {
        return;
    }

    for (auto i = out.begin(); i < out.end(); ++i) {
        if (i - out.begin() == (*x)) {
            cnt++;
            if (x + 1 < last) {
                ++x;
            }
        } else {
            if (cnt > 0) {
                swap(*i, *(i - cnt));
            }
        }
    }
    out.resize(out.size() - cnt);
}
