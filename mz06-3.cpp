#include <cmath>

template <typename T>
class Coord
{
public:
    T x, y;
    using value_type = T;
    Coord(T x = 0, T y = 0) : x(x), y(y){};
};

template <typename T>
T dist(Coord<T> field, Coord<T> a, Coord<T> b)
{
    T tp1 = std::abs(a.x - b.x);
    T tp2 = field.x - a.x + b.x;
    T lr = std::min(tp1, tp2);
    T tp3 = a.x + field.x - b.x;
    lr = std::min(lr, tp3);

    tp1 = std::abs(a.y - b.y);
    tp2 = field.y - a.y + b.y;
    T ud = std::min(tp1, tp2);
    tp3 = a.y + field.y - b.y;
    ud = std::min(ud, tp3);

    return std::max(ud, lr);
}
