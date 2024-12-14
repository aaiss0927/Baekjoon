#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<bool> v(101);

	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			v[i * j] = true;

	int n; cin >> n;

	cout << v[n];
}