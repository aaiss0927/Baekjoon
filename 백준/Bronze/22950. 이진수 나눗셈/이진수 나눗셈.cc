#include <iostream>
using namespace std;

bool div(string m, int k) {
    int len = m.length();

    for (int i = len - 1; i >= 0 && i >= len - k; i--)
        if (m[i] == '1')
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string m; cin >> m;
    int k; cin >> k;

    if (div(m, k))
        cout << "YES";

    else
        cout << "NO";
}