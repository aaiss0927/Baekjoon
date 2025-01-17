#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	queue<int> q[21];
	ll cnt = 0;

	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		int len = name.length();

		while (!q[len].empty() && i - q[len].front() > k)
			q[len].pop();
		
		cnt += q[len].size();
		q[len].push(i);
	}

	cout << cnt;
}