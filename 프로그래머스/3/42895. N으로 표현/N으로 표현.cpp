#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);
    dp[1].insert(N);
    if (N == number) return 1;
    int NN = N;
    
    for (int i = 2; i <= 8; i++) {
        NN = NN * 10 + N;
        dp[i].insert(NN);
        
        for (int j = 1; j < i; j++) {
            for (int a : dp[i - j]) {
                for (int b : dp[j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        if (dp[i].find(number) != dp[i].end()) return i;
    }
    
    return -1;
}