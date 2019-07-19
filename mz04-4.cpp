#include <vector>
#include <iostream>
#include <algorithm>

template <typename T, typename C>
C myremove(T n_first, T n_last, C first, C last)
{
    std::vector<int> v;
    for (auto it = n_first; it != n_last; ++it) {
        v.push_back(*it);
    }

    auto left = v.begin(), right = v.end();

    std::sort(left, right);
    right = std::unique(left, right);

    int cnt = 0;
    auto x = left;
    for ( ; x < right && (*x) < 0; ++x);
    if (x == right) {
        return last;
    }

    for (auto i = first; i < last; ++i) {
        if (i - first == (*x)) {
            cnt++;
            if (x + 1 < right) {
                ++x;
            }
        } else {
            if (cnt > 0) {
                std::swap(*i, *(i - cnt));
            }
        }
    }
    return last - cnt;
}
