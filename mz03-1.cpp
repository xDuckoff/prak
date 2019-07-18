#include <iostream>
#include <vector>
using namespace std;

void process(const vector<int> &in, vector<int> &out, int step)
{
    auto j = out.begin();
    for (auto i = in.begin(); i < in.end() && j < out.end(); i += step)
    {
        *j = *i;
        ++j;
        if (i + step > in.end()) {
            break;
        }
    }

    for (vector<int>::reverse_iterator i = out.rbegin(); i != out.rend(); i++)
    {
        cout << *i << endl;
    }
} 
