#include <iostream>
#include <vector>
using namespace std;

vector<bool> prime_table(1000001, true);

void check_prime() {
    prime_table[1] = false;

    for (int i = 2; i * i <= 1000000; i++) {
        if (prime_table[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                prime_table[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    check_prime();

    int T; cin >> T;

    while (T--) {
        int n; cin >> n;

        int cnt = 0;

        for (int i = 2; i <= n / 2; i++) {
            if (prime_table[i] && prime_table[n - i])
                cnt++;
        }

        cout << cnt << '\n';
    }
}