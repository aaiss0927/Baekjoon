#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> answer;
vector<int> v;

void bt(int low_bound) {
	if (answer.size() == m) {
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = low_bound; i < n; i++) {
		answer.push_back(v[i]);
		bt(i + 1);
		answer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v = vector<int>(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	bt(0);
}