#include <iostream>
#include <vector>
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

	int N, K;
	cin >> N >> K;
	vector<int> kit(N);

	for (int i = 0; i < N; i++) {
		cin >> kit[i];
	}

	vector<int> temp;
	for (int i = 0; i < N; i++) {
		temp.push_back(i);
	}

	vector<vector<int>> sequence(getF(N));
	int idx = 0;
	do {
		for (int i = 0; i < temp.size(); i++) {
			sequence[idx].push_back(temp[i]);
		}
		idx++;
	} while (next_permutation(temp.begin(), temp.end()));

	int count = 0;
	for (int i = 0; i < getF(N); i++) {
		int weight = 500;
		for (int j = 0; j < N; j++) {
			weight += (kit[sequence[i][j]] - K);
			if (weight < 500) {
				count++;
				break;
			}
		}
	}

	cout << getF(N) - count;
}