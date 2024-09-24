#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> is_correct(n);
    vector<int> score(n, 0);

    for (int i = 0; i < n; i++)
        cin >> is_correct[i];

    if (is_correct[0])
        score[0] = 1;

    for (int i = 1; i < n; i++) {
        if (is_correct[i]) {
            if (is_correct[i - 1])
                score[i] = score[i - 1] + 1;
            else
                score[i] = 1;
        }
    }

    int total_score = 0;

    for (int i = 0; i < n; i++)
        total_score += (is_correct[i] * score[i]);

    cout << total_score;
}