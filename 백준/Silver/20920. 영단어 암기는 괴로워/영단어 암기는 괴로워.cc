#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
map<string, int> voca;
vector<pair<string, int>> voca_vec;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second != p2.second) {
		return p1.second > p2.second;
	}

	if (p1.first.length() != p2.first.length()) {
		return p1.first.length() > p2.first.length();
	}

	return p1.first < p2.first;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		if (str.length() < m) continue;
		voca[str]++;
	}

	for (auto v : voca)
		voca_vec.push_back(v);

	sort(voca_vec.begin(), voca_vec.end(), cmp);

	for (auto v : voca_vec)
		cout << v.first << '\n';
}