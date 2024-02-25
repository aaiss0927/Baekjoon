#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str; cin >> str;
    int length = str.length();

    vector<int> alpha_cnt(26, 0);

    for (auto c : str) {
        alpha_cnt[c - 'A']++;
    }

    string new_str = str;

    int odd_cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (alpha_cnt[i] % 2 == 1) {
            odd_cnt++;
        }
    }

    if (length % 2 == 0 && odd_cnt > 0) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    if (length % 2 == 1 && odd_cnt > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    int idx = 0;
    int extra_idx;

    for (int i = 0; i < 26;) {
        if (alpha_cnt[i] >= 2) {
            new_str[idx] = new_str[length - 1 - idx] = i + 'A';
            idx++;
            alpha_cnt[i] -= 2;

            if (alpha_cnt[i] < 2) {
                if (alpha_cnt[i] == 1) {
                    extra_idx = i;
                }

                i++;
            }
        }
        
        else if (alpha_cnt[i] == 1) {
            extra_idx = i;
            i++;
        }

        else {
            i++;
        }
    }

    if (length % 2 == 1) {
        new_str[idx] = extra_idx + 'A';
    }

    cout << new_str;
}