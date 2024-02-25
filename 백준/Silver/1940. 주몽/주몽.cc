#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    int M; cin >> M;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    vector<int> ingdt_nums;
    vector<int> num_table(10000001, 0);

    for (int i = 0; i < N; i++) {
        int ingdt_num; cin >> ingdt_num;
        ingdt_nums.push_back(ingdt_num);
        num_table[ingdt_num]++;
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (ingdt_nums[i] < M && num_table[ingdt_nums[i]] >= 1) {
            num_table[ingdt_nums[i]]--;

            if (num_table[M - ingdt_nums[i]] >= 1) {
                num_table[M - ingdt_nums[i]]--;
                cnt++;
            }

            else {
                num_table[ingdt_nums[i]]++;
            }
        }
    }

    cout << cnt;
}