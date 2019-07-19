template <typename T, typename F>
T myfilter(const T& x, F f)
{
    T out{};
    for (auto &a : x) {
        if (f(a)) {
            out.insert(out.end(), a);
        }
    }
    return out;
}
