#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
long c;

bool cmp(tuple<long, int, int> t1, tuple<long, int, int> t2) {
	int cnt_1, rank_1, cnt_2, rank_2;
	tie(ignore, cnt_1, rank_1) = t1;
	tie(ignore, cnt_2, rank_2) = t2;
	
	if (cnt_1 > cnt_2) {
		return true;
	}

	else if (cnt_1 == cnt_2) {
		if (rank_1 < rank_2) {
			return true;
		}

		else {
			return false;
		}
	}

	else {
		return false;
	}
}

int main() {
	cin >> n >> c;
	map<long, pair<int, int>> m;

	int rank = 1;

	for (int i = 0; i < n; i++) {
		long num; cin >> num;

		map<long, pair<int, int>>::iterator it = m.find(num);

		if (it == m.end()) {
			m.insert({ num, { 1, rank } });
			rank++;
		}

		else {
			it->second.first++;
		}
	}

	vector<tuple<long, int, int>> v;

	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back({ it->first, it->second.first, it->second.second });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < get<1>(v[i]); j++) {
			cout << get<0>(v[i]) << ' ';
		}
	}
}