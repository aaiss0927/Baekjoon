#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v(3);

    for (int i = 0; i < 3; i++)
        cin >> v[i];

    string str; cin >> str;
    
    sort(v.begin(), v.end());
    int a, b, c;
    a = v[0];
    b = v[1];
    c = v[2];

    for (int i = 0; i < 3; i++) {
        if (str[i] == 'A')
            cout << a << ' ';
        else if (str[i] == 'B')
            cout << b << ' ';
        else
            cout << c << ' ';
    }
}