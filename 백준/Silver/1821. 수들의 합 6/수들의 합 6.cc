#include <iostream>
#include <vector>
using namespace std;

int n, f;

vector<int> factorial_dp(11);

int factorial(int num) {
    if (num == 0) {
        factorial_dp[0] = 1;
        return factorial_dp[0];
    }

    if (num == 1) {
        factorial_dp[1] = 1;
        return factorial_dp[1];
    }

    if (factorial_dp[num] != 0)
        return factorial_dp[num];

    else {
        factorial_dp[num] = num * factorial(num - 1);
        return factorial_dp[num];
    }
}

int C(int a, int b) {
    return (factorial(a) / (factorial(a - b) * factorial(b)));
}

int get_f(vector<int> arr) {
    int result = 0;

    for (int i = 0; i <= n - 1; i++) {
        result += (C(n - 1, i) * arr[i]);
    }

    return result;
}

vector<int> v;
vector<bool> is_used(11);

void bt() {
    if (v.size() == n) {
        if (f == get_f(v)) {
            for (int i = 0; i < n; i++)
                cout << v[i] << ' ';

            exit(0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (is_used[i])
            continue;

        is_used[i] = true;
        v.push_back(i);
        bt();
        v.pop_back();
        is_used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> f;
    bt();
    return 0;
}

