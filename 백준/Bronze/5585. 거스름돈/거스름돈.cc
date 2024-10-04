#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    n = 1000 - n;
    int cnt = 0;
    vector<int> mny = { 500, 100, 50, 10, 5, 1 };

    for (int i = 0; i < 6; i++) {
        cnt += n / mny[i];
        n %= mny[i];
    }

    cout << cnt;
}