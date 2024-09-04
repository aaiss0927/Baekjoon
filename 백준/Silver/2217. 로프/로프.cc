#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int maxi = -1;

    for (int i = 0; i < n; i++) {
        if (maxi < v[i] * (n - i))
            maxi = v[i] * (n - i);
    }

    cout << maxi;
}