#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, (int)sequence.size()};
    vector<int> prefix_sum = {0, sequence.front()};
    
    for (int i = 1; i < sequence.size(); i++)
        prefix_sum.push_back(prefix_sum.back() + sequence[i]);
    
    for (int i = 0; i < prefix_sum.size(); i++) {
        if (sequence[i] == k) {
            answer = {i, i};
            break;
        }
        
        int idx = lower_bound(prefix_sum.begin() + i + 1, prefix_sum.end(), prefix_sum[i] + k) - prefix_sum.begin();
        
        if (idx < prefix_sum.size() && prefix_sum[i] + k == prefix_sum[idx])
            if (idx - 1 - i < answer[1] - answer[0])
                answer = {i, idx - 1};
    }
    
    // answer = {1, 2, 3};
    // int i = lower_bound(answer.begin(), answer.end(), 4) - answer.begin();
    // cout << i;
    
    return answer;
}

// seq        = {1, 2, 3, 4, 5}
// prefix_sum = {1, 3, 6, 10, 15}

// k
// dp[m] - dp[n] = k
// dp[m] = dp[n] + k
// dp: 00 01 02 03 04
// 