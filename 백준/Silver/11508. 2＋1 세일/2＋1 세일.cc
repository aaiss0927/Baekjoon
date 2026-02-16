#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int total;
vector<int> costs;

int main() {
	cin >> n;
	total = 0;

	for (int i = 0; i < n; i++) {
		int cost; cin >> cost;
		total += cost;
		costs.push_back(cost);
	}

	sort(costs.rbegin(), costs.rend());
	
	for (int i = 2; i < n; i += 3)
		total -= costs[i];

	cout << total;
}