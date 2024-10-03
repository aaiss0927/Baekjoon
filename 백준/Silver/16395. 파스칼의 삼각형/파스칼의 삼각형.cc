#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    int dp[31][31];

    for (int i = 1; i <= 30; i++)
        dp[i][1] = dp[i][i] = 1;

    for (int i = 3; i <= 30; i++) {
        for (int j = 2; j < i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }

    cout << dp[n][k];
}