#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> last_name_first(26, 0);

    for (int i = 0; i < N; i++) {
        string last_name; cin >> last_name;

        last_name_first[last_name.front() - 'a']++;
    }

    string ans = "";

    for (int i = 0; i < 26; i++) {
        if (last_name_first[i] >= 5) {
            ans += (i + 'a');
        }
    }

    if (ans.empty()) {
        ans = "PREDAJA";
    }

    cout << ans;
}