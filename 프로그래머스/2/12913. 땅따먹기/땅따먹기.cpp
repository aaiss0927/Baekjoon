#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int n = land.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    for (int i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int maxi = 0;
            
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                
                maxi = max(maxi, dp[i - 1][k]);
            }
            
            dp[i][j] = maxi + land[i][j];
        }
    }
    
    answer = *max_element(dp[n - 1].begin(), dp[n - 1].end());

    return answer;
}