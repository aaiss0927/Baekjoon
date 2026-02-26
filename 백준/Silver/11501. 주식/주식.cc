#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        vector<int> prices;
        long long profit = 0;
        
        for (int i = 0; i < n; i++) {
            int price; cin >> price;
            prices.push_back(price);
        }
        
        reverse(prices.begin(), prices.end());
        int maxi = prices[0];
        
        for (int i = 1; i < n; i++) {
            if (prices[i] > maxi) {
                maxi = prices[i];
                continue;
            }
            
            profit += (maxi - prices[i]);
        }
        
        cout << profit << '\n';
    }
}