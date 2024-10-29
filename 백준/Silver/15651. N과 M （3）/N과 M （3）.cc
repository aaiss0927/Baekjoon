#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> answer;

void choose(int cur) {
    if (cur >= m) {
        for (int a : answer)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        answer.push_back(i);
        choose(cur + 1);
        answer.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    choose(0);
}