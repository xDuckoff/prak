struct Sum
{
private:
    int a, b;
public:
    Sum(int a = 0, int b = 0) : a(a), b(b)
    {
    }

    Sum(const Sum &a, const Sum &b) : a(a.a + b.a), b(a.b + b.b)
    {
    }

    int get() const
    {
        return a + b;
    }
};
