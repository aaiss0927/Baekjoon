#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
   int n; cin >> n;
   vector<int> A;
   vector<int> dp(n, INT_MAX);
   dp[0] = 0;
   
   for (int i = 0; i < n; i++) {
       int a; cin >> a;
       A.push_back(a);
   }
   
   for (int i = 0; i < n; i++) {
       for (int j = 1; j <= A[i]; j++) {
           if ((i + j >= n) || (dp[i] == INT_MAX)) continue;
           dp[i + j] = min(dp[i + j], dp[i] + 1);
       }
   }
   
   if (dp[n - 1] == INT_MAX) dp[n - 1] = -1;
   cout << dp[n - 1];
}