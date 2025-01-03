#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int g, p; cin >> g >> p;
    set<int> gate;

    for (int i = 1; i <= g; i++)
        gate.insert(i);

    for (int i = 0; i < p; i++) {
        int num; cin >> num;
        auto it = gate.upper_bound(num);

        if (it == gate.begin())
            break;

        gate.erase(--it);
    }

    cout << g - gate.size();
}