#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long dp[101];
    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= 100; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    int T; cin >> T;

    while (T--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}