struct Rational
{
private:
    int a, b;

    static int gcd(int a, int b)
    {
        int sgn = b / abs(b);
        while (a != 0 && b != 0) {
            if (b > a) {
                std::swap(a, b);
            }
            a %= b;
        }
        return (a + b) * sgn;
    }

    static int lcm(int a, int b)
    {
        return int((1ll * a * b) / gcd(a, b));
    }

    void norm()
    {
        int nod = gcd(a, b);
        a /= nod;
        b /= nod;
    }

public:
    Rational(int a = 0, int b = 1) : a(a), b(b)
    {
        norm();
    }

    Rational(const Rational &x) = default;

    Rational & Add(const Rational &x)
    {
        int z = lcm(x.b, b);
        a = a * (z / b) + x.a * (z / x.b);
        b = z;
        norm();
        return *this;
    }

    Rational & Substract(const Rational &x)
    {
        int z = lcm(b, x.b);
        a = a * (z / b) - x.a * (z / x.b);
        b = z;
        norm();
        return *this;
    }

    Rational & Multiply(const Rational &x)
    {
        int bc = gcd(b, x.a), ad = gcd(a, x.b);
        a = (x.a / bc) * (a / ad);
        b = (b / bc) * (x.b / ad);
        norm();
        return *this;
    }

    Rational & Divide(const Rational &x)
    {
        int bc = gcd(b, x.b), ad = gcd(a, x.a);
        a = (x.b / bc) * (a / ad);
        b = (b / bc) * (x.a / ad);
        norm();
        return *this;
    }

    bool EqualTo(const Rational &x) const
    {
        return a == x.a && b == x.b;
    }

    bool IsInteger() const
    {
        return b == 1;
    }

    long long CompareTo(const Rational &x) const
    {
        return 1ll * a * x.b - 1ll * b * x.a;
    }

    std::string ToString() const
    {
        return std::to_string(a) + ":" + std::to_string(b);
    }

};

