#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> pred(n);

    for (int i = 0; i < n; i++)
        cin >> pred[i];

    sort(pred.begin(), pred.end());

    long long result = 0;

    for (int i = 0; i < n; i++)
        result += abs(pred[i] - (i + 1));

    cout << result;
}