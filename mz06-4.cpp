#include <cmath>

namespace Game {

    template<typename T>
    class Coord {
    public:
        T row, col;
        typedef T value_type;

        Coord(T row = 0, T col = 0) : row(row), col(col) {};
    };

    template<typename T>
    T dist(Coord<T> field, Coord<T> a, Coord<T> b) {
        T dif_col = std::abs(a.col - b.col);
        T dif_row = std::abs(a.row - b.row);

        T dist = dif_col;
        T boost = dist / 2;

        if (dist & 1) {
            if (a.col & 1) {
                if ((b.col > a.col && b.row < a.row) || (b.col < a.col && b.row < a.row)) {
                    ++boost;
                }
            } else {
                if ((b.col < a.col && b.row > a.row) || (b.col > a.col && b.row > a.row)) {
                    ++boost;
                }
            }
        }

        return dif_col + dif_row - std::min(boost, dif_row);
    }
}
