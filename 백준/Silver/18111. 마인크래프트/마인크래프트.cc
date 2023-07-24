#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long B;
	cin >> N >> M >> B;

	vector<vector<int>> h(N, vector<int>(M));
	vector<int> h_arr;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> h[i][j];
			h_arr.push_back(h[i][j]);
		}
	}

	sort(h_arr.begin(), h_arr.end());
	vector<pair<long, int>> result(h_arr.back() - h_arr.front() + 1);

	for (int temp = h_arr.front(); temp <= h_arr.back(); temp++) {
		vector<int> h_arr_(h_arr.size());
		for (int i = 0; i < h_arr.size(); i++) {
			h_arr_[i] = h_arr[i];
		}
		result[temp - h_arr.front()].second = temp;
		long B_ = B;
		bool flag = true;
		for (int i = h_arr.size() - 1; i >= 0; i--) {
			if (h_arr_[i] > temp) {
				B_ += long(h_arr_[i] - temp);
				result[temp - h_arr.front()].first += long(2 * (h_arr_[i] - temp));
				h_arr_[i] = temp;
			}
			if (h_arr_[i] < temp) {
				B_ -= long(temp - h_arr_[i]);
				if (B_ < 0) {
					flag = false;
					result[temp - h_arr.front()].first = -1;
					break;
				}
				result[temp - h_arr.front()].first += long(temp - h_arr_[i]);
				h_arr_[i] = temp;
			}
		}
	}

	sort(result.begin(), result.end(), cmp);
	pair<long, int> m;
	for (int i = 0; i < result.size(); i++) {
		if (result[i].first != -1) {
			m = result[i];
			break;
		}
	}
	cout << m.first << " " << m.second;
}