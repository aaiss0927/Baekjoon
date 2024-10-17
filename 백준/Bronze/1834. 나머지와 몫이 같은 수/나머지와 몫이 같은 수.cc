#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n; cin >> n;
    cout << (n + 1) * n * (n - 1) / 2;
}

// a = N * b + b (0 <= b < N)
// a = (N + 1) * b
// Sa = (N + 1) * (1 + ... + (N - 1))
// Sa = (N + 1) * N * (N - 1) / 2