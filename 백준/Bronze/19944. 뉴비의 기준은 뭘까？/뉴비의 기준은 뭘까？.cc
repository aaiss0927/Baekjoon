#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	if ((M == 1) || (M == 2)) {
		cout << "NEWBIE!";
	}
	else if ((M > 2) && (M <= N)) {
		cout << "OLDBIE!";
	}
	else {
		cout << "TLE!";
	}
}