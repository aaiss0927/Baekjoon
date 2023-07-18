#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void getP(int M, int N, vector<int>& v) {
	bool* check = new bool[N + 1] { false };
	check[1] = true;

	for (int i = 2; i <= sqrt(N); i++) {
		if (check[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			check[i * j] = true;
		}
	}

	for (int i = M; i <= N; i++) {
		if (!check[i]) {
			v.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<int> P;
	getP(M, N, P);

	if (P.empty()) {
		cout << -1;
		return 0;
	}

	int r = 0;
	for (int i = 0; i < P.size(); i++) {
		r += P[i];
	}
	cout << r << '\n' << P.front();
}