#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> input;
	vector<pair<int, int>> output;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		input.emplace_back(x, y);
	}

	sort(input.begin(), input.end(), cmp);
	output.push_back(input.front());
	int last = output.front().second;

	for (int i = 1; i < input.size(); i++) {
		if (input[i].first >= last) {
			output.push_back(input[i]);
			last = output.back().second;
		}
	}

	cout << output.size();
}