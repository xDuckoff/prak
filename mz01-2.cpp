#include <iostream>
 
struct A
{
private:
    int x;
    bool flag;
public:
    A() : flag(true)
    {
        std::cin >> x;
    }

    A(A &b)
    {
        std::cin >> x;
        x += b.x;
        b.flag = false;
    }

    ~A()
    {
        if (flag) {
            std::cout << x << std::endl;
        }
    }
};
