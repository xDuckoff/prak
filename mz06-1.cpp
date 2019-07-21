#include <iostream>
#include <string>
using namespace std;

struct A
{
private:    
    string s;
public:
    A(const string &s) : s(s){};
    ~A()
    {
        cout << s << endl;
    }
};

struct Exept
{
};

void foo()
{
    string s;
    if (cin >> s) {
        A a(s);
        foo(); 
    }
    throw Exept();
}

int main()
{
    try{
        foo();
    } catch(const Exept &e) {

    }
}
