#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> profit(n);
	vector<int> cost(n);

	for (int i = 0; i < n; i++)
		cin >> profit[i];

	for (int i = 0; i < n; i++)
		cin >> cost[i];

	vector<int> profit_(profit);
	sort(profit_.begin(), profit_.end());
	reverse(profit_.begin(), profit_.end());

	int first = profit_[0];
	int second = profit_[1];

	for (int i = 0; i < n; i++) {
		if (profit[i] == first)
			cout << profit[i] - second << ' ';

		else
			cout << profit[i] - first << ' ';
	}
}