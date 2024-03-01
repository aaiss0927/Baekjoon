#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> strs;
vector<string> nums;

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length()) {
		return true;
	}

	else if (s1.length() == s2.length()) {
		return s1 < s2;
	}

	else {
		return false;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	while (n--) {
		string str; cin >> str;

		strs.push_back(str);
	}

	for (int i = 0; i < strs.size(); i++) {
		string num = "";

		for (int j = 0; j < strs[i].length(); j++) {
			if (isdigit(strs[i][j])) {
				num += strs[i][j];
			}

			else {
				if (!num.empty()) {
					nums.push_back(num);
					num = "";
				}
			}
		}

		if (!num.empty()) {
			nums.push_back(num);
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		while (nums[i].length() > 1 && nums[i].front() == '0') {
			nums[i].erase(0, 1);
		}
	}

	sort(nums.begin(), nums.end(), cmp);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << '\n';
	}
}