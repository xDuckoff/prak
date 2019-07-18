#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Average
{
    double sum;
    size_t n, m;

    explicit Average(size_t m = 0, double sum = 0) : sum(0), n(0), m(m)
    {
    }

    void operator()(double x)
    {
        sum += x;
        n++;
        if (n == m) {
            cout << (sum / n) << endl;
        }
    }
};

void myerase(vector<double> &v)
{
    size_t excess = v.size() * 10 / 100;
    v.erase(v.begin(), v.begin() + excess);
    v.erase(v.end() - excess, v.end());
}

int main()
{
    vector <double> v;
    double x;
    while (cin >> x) {
        v.push_back(x);
    }

    myerase(v);
    sort(v.begin(), v.end());
    myerase(v);

    Average f(v.size());
    for_each(v.begin(), v.end(), f);
}
