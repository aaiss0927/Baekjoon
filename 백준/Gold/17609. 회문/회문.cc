#include <iostream>
#include <algorithm>
using namespace std;

int cnt;

void palindrome(string str, int s, int e) {
    cnt = 0;

    while (s <= e) {
        if (str[s] == str[e]) {
            s++; e--;
        }

        else {
            if (str[s] == str[e - 1]) {
                e--;
                cnt++;
            }

            else if (str[s + 1] == str[e]) {
                s++;
                cnt++;
            }

            else {
                s++; e--;
                cnt += 2;
            }
        }

        if (cnt >= 2) {
            cnt = 2;
            break;
        }
    }
}

// abdcddcba
// abcddcdba

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;

    while (T--) {
        string str; cin >> str;

        int result_1, result_2;

        palindrome(str, 0, str.length() - 1);
        result_1 = cnt;

        reverse(str.begin(), str.end());

        palindrome(str, 0, str.length() - 1);
        result_2 = cnt;

        cout << min(result_1, result_2) << '\n';
    }
}