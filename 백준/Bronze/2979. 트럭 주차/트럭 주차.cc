#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;

    vector<int> cost_table = { 0, A, 2 * B, 3 * C };

    vector<int> time_table(101, 0);

    for (int i = 0; i < 3; i++) {
        int s, e; cin >> s >> e;

        for (int j = s; j < e; j++) {
            time_table[j]++;
        }
    }

    int ans = 0;

    for (int i = 1; i <= 100; i++) {
        ans += cost_table[time_table[i]];
    }

    cout << ans;
}