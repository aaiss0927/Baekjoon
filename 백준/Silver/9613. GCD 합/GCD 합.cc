#include <iostream>
#include <vector>
using namespace std;

long long gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        long long ans = 0;
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            v.push_back(num);
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++)
                ans += gcd(v[i], v[j]);
        }
        
        cout << ans << '\n';
    }
}