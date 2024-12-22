#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> v;
vector<int> idx;
vector<int> ab_sum;
vector<int> cd_sum;

void bt() {
    if (idx.size() == 2) {
        ab_sum.push_back(v[idx[0]][0] + v[idx[1]][1]);
        cd_sum.push_back(v[idx[0]][2] + v[idx[1]][3]);
        return;
    }

    for (int i = 0; i < n; i++) {
        idx.push_back(i);
        bt();
        idx.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v = vector<vector<int>>(n, vector<int>(4));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> v[i][j];

    bt();
    sort(ab_sum.begin(), ab_sum.end());

    long long result = 0;

    for (int target : cd_sum) {
        int lower_idx = lower_bound(ab_sum.begin(), ab_sum.end(), -target) - ab_sum.begin();
        int upper_idx = upper_bound(ab_sum.begin(), ab_sum.end(), -target) - ab_sum.begin();

        result += (upper_idx - lower_idx);
    }

    cout << result;
}