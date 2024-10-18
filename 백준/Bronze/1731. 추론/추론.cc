#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int q;

    if (v[1] - v[0] == v[2] - v[1]) {
        q = v[1] - v[0];
        cout << v[n - 1] + q;
    }
    else {
        q = v[1] / v[0];
        cout << v[n - 1] * q;
    }
}