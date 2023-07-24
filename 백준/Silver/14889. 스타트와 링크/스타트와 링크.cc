#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long idx = 0;
vector<int> arr;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

long getC(int n, int k) {
	long nm = 1;
	long dn = 1;

	for (int i = k; i >= 1; i--) {
		nm *= i + (n - k);
		dn *= i;
		int gcd = GCD(nm, dn);
		nm /= gcd;
		dn /= gcd;
	}

	return nm / dn;
}

void search(int k, vector<vector<int>>& start) {
	if (k == N) {
		if (arr.size() == N / 2) {
			for (int i = 0; i < arr.size(); i++) {
				start[idx].push_back(arr[i]);
			}
			idx++;
		}
		return;
	}
	else {
		arr.push_back(k + 1);
		search(k + 1, start);
		arr.pop_back();
		search(k + 1, start);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	vector<bool> all(N);
	vector<vector<int>> start(getC(N, N / 2));
	vector<vector<int>> link(getC(N, N / 2));
	search(0, start);
	for (int i = 0; i < getC(N, N / 2); i++) {
		for (int i = 0; i < N; i++) {
			all[i] = false;
		}
		for (int j = 0; j < N / 2; j++) {
			all[start[i][j] - 1] = true;
		}
		for (int j = 0; j < N; j++) {
			if (!all[j]) {
				link[i].push_back(j + 1);
			}
		}
	}
	
	vector<int> result(getC(N, N / 2));
	for (int i = 0; i < getC(N, N / 2); i++) {
		int sum_start = 0;
		int sum_link = 0;
		for (int j = 0; j < N / 2; j++) {
			for (int k = j + 1; k < N / 2; k++) {
				sum_start += board[start[i][j] - 1][start[i][k] - 1] + board[start[i][k] - 1][start[i][j] - 1];
				sum_link += board[link[i][j] - 1][link[i][k] - 1] + board[link[i][k] - 1][link[i][j] - 1];
			}
		}
		result[i] = abs(sum_start - sum_link);
	}
	sort(result.begin(), result.end());
	cout << result.front();
}
