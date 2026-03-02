#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s) {
    stack<char> st;
    
    for (auto const& c : s) {
        if (st.empty()) st.push(c);
        
        else {
            if (st.top() == ')') st.push(c);
            
            else {
                if (c == ')') st.pop();
                else st.push(c);
            }
        }
    }
    
    if (!st.empty()) return false;
    else return true;
}