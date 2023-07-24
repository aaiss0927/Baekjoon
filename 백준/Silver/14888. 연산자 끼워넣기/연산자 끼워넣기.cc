#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getF(int n) {
	if (n == 0) {
		return 1;
	}
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
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	vector<int> op_count(4);
	for (int i = 0; i < 4; i++) {
		cin >> op_count[i];
	}

	int total_case = getF(N - 1) / (getF(op_count[0]) * getF(op_count[1]) * getF(op_count[2]) * getF(op_count[3]));
	vector<vector<int>> op(total_case);

	vector<int> temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < op_count[i]; j++) {
			temp.push_back(i);
		}
	}

	int idx = 0;
	do {
		for (int i = 0; i < temp.size(); i++) {
			op[idx].push_back(temp[i]);
		}
		idx++;
	} while (next_permutation(temp.begin(), temp.end()));

	vector<int> result(total_case, num[0]);
	for (int i = 0; i < total_case; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (op[i][j] == 0) {
				result[i] += num[j + 1];
			}
			else if (op[i][j] == 1) {
				result[i] -= num[j + 1];
			}
			else if (op[i][j] == 2) {
				result[i] *= num[j + 1];
			}
			else if (op[i][j] == 3) {
				result[i] /= num[j + 1];
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.back() << '\n' << result.front();
}