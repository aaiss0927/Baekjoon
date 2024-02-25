#include <iostream>
#include <vector>
using namespace std;

bool is_present_type(string type, vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == type) {
            return true;
        }
    }

    return false;
}

int get_type_idx(string type, vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == type) {
            return i;
        }
    }

    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int idx = 0;

        vector<int> each_cnt(30, 0);
        vector<string> check_dup(30, "");

        while (n--) {
            string d_name, d_type;
            cin >> d_name >> d_type;

            if (!is_present_type(d_type, check_dup)) {
                each_cnt[idx] += 1;
                check_dup[idx] = d_type;
                idx++;
            }

            else {
                each_cnt[get_type_idx(d_type, check_dup)] += 1;
            }
        }

        int ans = 1;

        for (int i = 0; i < idx; i++) {
            ans *= (each_cnt[i] + 1);
        }

        ans--;

        cout << ans << '\n';
    }
}