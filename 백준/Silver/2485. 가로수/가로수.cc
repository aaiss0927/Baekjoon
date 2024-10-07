#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);

    if (b == 1)
        return 1;

    if (b == 0)
        return a;

    return gcd(a - b, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vector<long long> tree(n);

    for (int i = 0; i < n; i++)
        cin >> tree[i];

    vector<long long> gap;

    for (int i = 1; i < n; i++)
        gap.push_back(tree[i] - tree[i - 1]);

    long long d = gap[0];

    for (int i = 1; i < n - 1; i++)
        d = gcd(d, gap[i]);

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
        ans += ((gap[i] / d) - 1);

    cout << ans;
}