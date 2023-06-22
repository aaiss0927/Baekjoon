#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int result = pow(pow(2, N) + 1, 2);
	cout << result;
}