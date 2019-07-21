#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

struct Result
{
private:
    uint64_t res;
public:
    Result(int64_t r) : res(r){};
    uint64_t get_r() const
    {
        return res;
    }
};

void f(uint64_t a, uint64_t b, uint32_t k)
{
    if (k == 0) {
        throw Result(a + b);
    } else if (k > 0 && b == uint64_t(1)) {
        throw Result(a);
    } else {
        try{
            f(a, b - 1, k);
        } catch(const Result &r) {
            f(a, r.get_r(), k - 1);
        }    
    }
}

int main()
{
    uint64_t a, b;
    uint32_t k;
            
    while (cin >> a >> b >> k) {
        try{
            f(a, b, k);
        } catch(const Result &r) {
            cout << r.get_r() << endl;
        }
    }    
}
