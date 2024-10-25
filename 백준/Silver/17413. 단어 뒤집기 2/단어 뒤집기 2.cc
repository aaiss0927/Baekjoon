#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    getline(cin, str);

    stack<char> s;
    int len = str.length();
    bool flag_tag = false;

    for (int i = 0; i < len; i++) {
        if (str[i] == '<') {
            flag_tag = true;
            cout << str[i];
            continue;
        }

        if (str[i] == '>') {
            flag_tag = false;
            cout << str[i];
            continue;
        }

        if (flag_tag) {
            cout << str[i];
            continue;
        }

        if (str[i] != ' ')
            s.push(str[i]);

        if ((str[i] == ' ' || i == len - 1 || (i + 1 <= len - 1 && str[i + 1] == '<')) && !s.empty()) {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            
            if (str[i] == ' ')
                cout << ' ';
        }
    }
}