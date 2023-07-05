#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<pair<char, int>> s;
	vector<pair<int, int>> iron;
	vector<int> laser;
	int idx = 0;
	
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(make_pair(str[i], idx));
			idx++;
		}
		else {
			s.push(make_pair(str[i], idx));
			idx++;
			int start, end;
			end = s.top().second;
			s.pop();
			start = s.top().second;
			s.pop();
			if (end - start == 1) {
				laser.push_back(end);
			}
			else {
				iron.push_back(make_pair(start, end));
			}
		}
	}

	int count = 0;
	for (int i = 0; i < iron.size(); i++) {
		for (int j = 0; j < laser.size(); j++) {
			if (laser[j] > iron[i].first && laser[j] < iron[i].second) {
				count++;
			}
		}
	}
	cout << count + iron.size();
}