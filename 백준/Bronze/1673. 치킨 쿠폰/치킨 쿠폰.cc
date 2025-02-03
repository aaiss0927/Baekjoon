#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, k;
    while (cin >> n >> k) {
        ll ans = 0;
        ll stamp = 0;
        ll coupon = n;

        while (coupon) {
            ans += coupon;
            stamp += coupon;
            coupon = stamp / k;
            stamp %= k;
        }

        cout << ans << '\n';
    }
}