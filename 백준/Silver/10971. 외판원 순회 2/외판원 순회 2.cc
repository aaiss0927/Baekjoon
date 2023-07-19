#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int getF(int n) {
	if (n == 1) {
		return 1;
	}
	return n * getF(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int** w = new int*[N];
	for (int i = 0; i < N; i++) {
		w[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}

	vector<int>* visit_case = new vector<int>[getF(N)];
	long min = 10000000;
	int cnt = 0;
	int* city = new int[N];
	for (int i = 0; i < N; i++) {
		city[i] = i;
	}

	do {
		vector<int> visit_case;
		for (int i = 0; i < N; i++) {
			visit_case.push_back(city[i]);
		}

		bool flag = true;

		int cost = 0;
		for (int j = 0; j < N - 1; j++) {
			if (w[visit_case[j]][visit_case[j + 1]] == 0) {
				flag = false;
				break;
			}
			cost += w[visit_case[j]][visit_case[j + 1]];
		}
		if (w[visit_case[N - 1]][visit_case[0]] == 0) {
			flag = false;
		}
		if (!flag) {
			continue;
		}
		cost += w[visit_case[N - 1]][visit_case[0]];
		if (cost < min) {
			min = cost;
		}
	} while (next_permutation(city, city + N));

	cout << min;
}