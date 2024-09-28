#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> menu(n);

    for (int i = 0; i < n; i++)
        cin >> menu[i];

    int m; cin >> m;
    vector<int> pick(m);

    for (int i = 0; i < m; i++)
        cin >> pick[i];

    int cost = 0;

    for (int i = 0; i < m; i++)
        cost += menu[pick[i] - 1];

    cout << cost;
}