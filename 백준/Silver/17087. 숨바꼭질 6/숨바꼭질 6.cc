#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long n, s;
vector<long long> v;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    
    if (b == 0) return a;
    
    return gcd(a % b, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        v.push_back(abs(a - s));
    }
    
    int ans = v[0];
    
    for (const auto& v_ : v)
        ans = gcd(ans, v_);
        
    cout << ans;
}