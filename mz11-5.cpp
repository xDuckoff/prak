#include <iostream>
#include <stack>
#include <algorithm>

int main()
{
    std::stack<std::string> st;
    char c;
    
    while (std::cin >> c) {
        std::string op;
        op.push_back(c);

        if (c < 'a' || c > 'z') {
            std::string a = st.top();
            st.pop();
            std::string b = st.top();
            st.pop();
            st.push("(" + b + op + a + ")"); 
        } else {
            st.push(op);
        }
    }

    std::cout << st.top();
}
