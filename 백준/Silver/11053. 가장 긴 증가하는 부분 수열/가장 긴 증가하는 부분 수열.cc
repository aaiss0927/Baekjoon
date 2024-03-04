#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
int dp[1001];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        dp[i] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    
    cout << *max_element(dp, dp + n);
}