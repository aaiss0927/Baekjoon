#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> vote(3, 0);

	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		vote[v + 1]++;
	}

	string ans;

	if (vote[1] >= ((n + 1) / 2))
		ans = "INVALID";

	else {
		if (vote[2] > vote[0])
			ans = "APPROVED";
		else
			ans = "REJECTED";
	}

	cout << ans;
}