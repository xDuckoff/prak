#include <complex>
#include <array>

namespace Equations
{
    template<typename T>
    auto quadratic(const T &v)
    {
        auto a = v[2];
        auto b = v[1];
        auto c = v[0];
        constexpr typename T::value_type zero(0, 0);

        if (a == zero && b == zero && c == zero) {
            return std::make_pair(false, std::vector<typename T::value_type>(0));
        } else if (a == zero && b == zero && c != zero) {
            return std::make_pair(true, std::vector<typename T::value_type>(0));
        } else if (a == zero && b != zero) {
            return std::make_pair(true, std::vector<typename T::value_type>{-c / b});
        }

        //it's quadratic equation
        auto D = std::sqrt(b * b - typename T::value_type::value_type(4) * a * c);
        a *= typename T::value_type::value_type(2);
        std::vector<typename T::value_type> out{(-b + D) / a, (-b - D) / a};
        return make_pair(true, out);
    }
}
