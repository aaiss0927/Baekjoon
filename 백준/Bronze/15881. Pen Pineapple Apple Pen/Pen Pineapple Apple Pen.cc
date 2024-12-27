#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string str; cin >> str;

    int idx = 0;
    int cnt = 0;

    while (str.find("pPAp", idx) < str.length()) {
        idx = str.find("pPAp", idx) + 4;
        cnt++;

        if (idx >= str.length())
            break;
    }

    cout << cnt;
}