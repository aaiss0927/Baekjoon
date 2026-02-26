#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long get_cnt(long long n, long long p) {
    long long cnt = 0;
    
    for (long long i = p; i <= n; i *= p) {
        if (i > n) break;
        
        cnt += (n / i);
    }
    
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    long long n, m; cin >> n >> m;
    long long cnt_2 = get_cnt(n, 2) - get_cnt(m, 2) - get_cnt(n-m, 2);
    long long cnt_5 = get_cnt(n, 5) - get_cnt(m, 5) - get_cnt(n-m, 5);
    
    cout << min(cnt_2, cnt_5);
}

// 25C12 = (25*24*23*22*,,,*14) / (12*11*,,,*1)
// numer / denom 각각 2개수 5개수 구하기