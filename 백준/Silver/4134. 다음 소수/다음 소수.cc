#include <iostream>
#include <cmath>
using namespace std;
// 128MB = 2^17B
// 4000000007

bool is_prime(long long num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;

    while (T--) {
        long long n; cin >> n;

        if (n == 0 || n == 1 || n == 2) {
            cout << 2 << '\n';
            continue;
        }

        if (n % 2 == 0)
            n++;

        while (!is_prime(n))
            n += 2;

        cout << n << '\n';
    }
}