#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    
    if (a == 0) return b;
    
    return gcd(b % a, a);
}

int main() {
    int T; cin >> T;
    
    while (T--) {
        int m, n, x, y; cin >> m >> n >> x >> y;
        int lcm = m * n / gcd(m, n);
        bool flag = false;
        
        int a, b;
        a = b = 0;
        
        while (m * a + x <= lcm) {
            if (m * a + x < n * b + y) a++;
            else if (m * a + x > n * b + y) b++;
            else {
                flag = true;
                cout << m * a + x << '\n';
                break;
            }
        }
        
        if (!flag) cout << "-1\n";
    }
}

// <3:11> - 23
// 23 = 10a + 3
// 23 = 12b + 11
// 23 = 60c + ()
// 13 23 33 43 53
// 11 23 35 47 59

// maxi 내에서
// mi + x vector
// nj + y vector
// 만들고 공통되는 1개 원소 찾기
// 없다면 -1 출력