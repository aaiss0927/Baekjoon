#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> point(n);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		point[i] = { x, y };
	}

	int dist = 0;
	for (int i = 1; i < n; i++) {
		dist += abs(point[i].first - point[i - 1].first)
			+ abs(point[i].second - point[i - 1].second);
	}

	int ans = INT_MAX;
	for (int i = 1; i < n - 1; i++) {
		int sub = abs(point[i].first - point[i - 1].first)
			+ abs(point[i].second - point[i - 1].second)
			+ abs(point[i + 1].first - point[i].first)
			+ abs(point[i + 1].second - point[i].second);
		
		int add = abs(point[i + 1].first - point[i - 1].first)
			+ abs(point[i + 1].second - point[i - 1].second);

		int new_dist = dist - sub + add;

		if (new_dist < ans)
			ans = new_dist;
	}

	cout << ans;
}