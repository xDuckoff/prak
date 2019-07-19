
#include <functional>
#include <vector>

template <typename T, typename F>
void myapply(T first, T last, F func)
{
    for (auto it = first; it != last; ++it) {
        func(*it);
    }
}

template <typename C, typename P>
auto myfilter2(C first, C last, P func)
{
    std::vector< std::reference_wrapper<typename C::value_type>> out;
    for (auto it = first; it != last; ++it) {
        if (func(*it)) {
            out.push_back(*it);
        }
    }

    return out;
}

template <typename C1, typename P1>
auto myfilter2(C1 *first, C1 *last, P1 func)
{
    std::vector<std::reference_wrapper <C1>> out;
    for (auto it = first; it != last; ++it) {
        if (func(*it)) {
            out.push_back(*it);
        }
    }

    return out;
}
