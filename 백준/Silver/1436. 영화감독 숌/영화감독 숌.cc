#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> title_nums;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n; n--;

	int cur_num = 666;

	while (title_nums.size() < 10000) {
		if (to_string(cur_num).find("666") != string::npos) {
			title_nums.push_back(cur_num);
		}

		cur_num++;
	}

	sort(title_nums.begin(), title_nums.end());

	cout << title_nums[n];
}