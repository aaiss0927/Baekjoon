#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K; cin >> N >> K;

    vector<int> temps;

    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        temps.push_back(temp);
    }

    vector<int> dp(N - K + 1, 0);

    for (int i = 0; i < K; i++) {
        dp[0] += temps[i];
    }

    int ans = dp[0];

    for (int i = 1; i <= N - K; i++) {
        dp[i] = dp[i - 1] - temps[i - 1] + temps[i + K - 1];

        ans = max(ans, dp[i]);
    }

    cout << ans;
}