template <typename T>
auto process(const T& x, int n = 3)
{
    int cnt = 0;
    typename T::value_type sum{};
    for (auto it = x.rbegin(); it != x.rend() && cnt < n; ++it) {
        sum += *it;
        ++cnt;
        ++it;
        if (it == x.rend()) {
            break;
        }
    }
    return sum;
}
