#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int idx = 1;
	while (n--) {
		vector<int> line(3);
		cin >> line[0] >> line[1] >> line[2];
		sort(line.begin(), line.end());

		cout << "Scenario #" << idx << ":\n";

		if (pow(line[0], 2) + pow(line[1], 2) == pow(line[2], 2))
			cout << "yes\n\n";

		else
			cout << "no\n\n";

		idx++;
	}
}