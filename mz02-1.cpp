#include <iostream>
#include <cstdio>
#include <cmath>
 
namespace numbers
{
    struct complex
    {
        double re, im;
    public:
        complex(double a = 0, double b = 0) : re(a), im(b)
        {
        }

        explicit complex(const char *s)
        {
            sscanf(s, "(%lf,%lf)", &re, &im);
        }

        double get_re() const
        {
            return re;
        }

        double get_im() const
        {
            return im;
        }

        double abs2() const
        {
            return (re * re + im * im);
        }

        double abs() const
        {
            return sqrt(abs2());
        }

        void to_string(char *buf, size_t size) const
        {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }

        friend complex operator + (const complex & x, const complex & y);
        friend complex operator - (const complex & x, const complex & y);
        friend complex operator * (const complex & x, const complex & y);
        friend complex operator / (const complex & x, const complex & y);
        friend complex operator ~ (const complex & x);
        friend complex operator - (const complex & x);
    };

    complex operator + (const complex & x, const complex & y)
    {
        complex c(x.re + y.re, x.im + y.im);
        return c;
    }

    complex operator - (const complex & x, const complex & y)
    {
        complex c(x.re - y.re, x.im - y.im);
        return c;
    }

    complex operator * (const complex & x, const complex & y)
    {
        double a1 = x.re, b1 = x.im, a2 = y.re, b2 = y.im;
        complex c(a1 * a2 - b1 * b2, a1 * b2 + b1 * a2);
        return c;
    }

    complex operator / (const complex & x, const complex & y)
    {
        double a1 = x.re, b1 = x.im, a2 = y.re, b2 = y.im;
        double z = a2 * a2 + b2 * b2;
        complex c((a1 * a2 + b1 * b2) / z, (b1 * a2 - a1 * b2) / z);
        return c;
    }

    complex operator - (const complex & x)
    {
        complex c(-x.re, -x.im);
        return c;
    }

    complex operator ~ (const complex & x)
    {
        complex c(x.re, -x.im);
        return c;
    }
}
