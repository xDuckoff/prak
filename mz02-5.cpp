#include <iostream>
using namespace std;

struct S
{
    int a;
    bool flag, empty;

public:
    S(): flag(false), empty(true)
    {
        if (cin >> a) {
            flag = true;
            empty = false;
        }
    }

    S(const S &x): flag(false), empty(x.empty)
    {
        if (cin >> a) {
            flag = true;
            a += x.a;
        } else {
            a = x.a;
        }
    }

    explicit operator bool() const
    {
        return flag;
    }

    ~S()
    {
        if (!flag && !empty) {
            cout << a << endl;
        }
    }
};
