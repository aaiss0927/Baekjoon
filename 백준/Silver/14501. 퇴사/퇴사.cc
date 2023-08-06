#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<int> arr;
vector<vector<int>> case_able;

void search(int k, vector<pair<int, int>>& v) {
	if (k == N) {
		cnt++;
		vector<bool> isUsed(N, false);
		bool flag = true;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < v[arr[i] - 1].first; j++) {
				if (arr[i] - 1 + j >= N) {
					flag = false;
					break;
				}
				if (isUsed[arr[i] - 1 + j]) {
					flag = false;
					break;
				}
				else {
					isUsed[arr[i] - 1 + j] = true;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			vector<int> temp;
			for (int i = 0; i < arr.size(); i++) {
				temp.push_back(arr[i]);
			}
			case_able.push_back(temp);
		}
		return;
	}
	else {
		arr.push_back(k + 1);
		search(k + 1, v);
		arr.pop_back();
		search(k + 1, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t >> p;
		v.emplace_back(t, p);
	}

	search(0, v);

	int max = 0;
	for (int i = 0; i < case_able.size(); i++) {
		int result = 0;
		for (int j = 0; j < case_able[i].size(); j++) {
			result += v[case_able[i][j] - 1].second;
		}
		if (result > max) {
			max = result;
		}
	}
	cout << max;
}