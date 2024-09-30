#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);

    if (str.length() <= 2 || !(str.front() == '\"' && str.back() == '\"'))
        cout << "CE";
    else
        for (int i = 1; i < str.length() - 1; ++i)
            cout << str[i];
}