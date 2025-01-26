#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> score(n);

    for (int i = 0; i < n; i++)
        cin >> score[i];

    int x, y; cin >> x >> y;
    int rel_cnt, abs_cnt;
    rel_cnt = abs_cnt = 0;

    rel_cnt = n * x / 100;

    for (int i = 0; i < n; i++)
        if (score[i] >= y)
            abs_cnt++;

    cout << rel_cnt << ' ' << abs_cnt;
}