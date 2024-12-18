#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> total_line(m);
	vector<int> single_line(m);

	for (int i = 0; i < m; i++) {
		int total, single; cin >> total >> single;
		total_line[i] = total;
		single_line[i] = single;
	}

	int total_min, single_min;
	total_min = *min_element(total_line.begin(), total_line.end());
	single_min = *min_element(single_line.begin(), single_line.end());

	if (total_min > 6 * single_min) {
		cout << n * single_min;
		return 0;
	}

	int first = ceil(double(n) / 6) * total_min;
	int second = (n / 6) * total_min + (n % 6) * single_min;

	int result = (first < second) ? first : second;
	cout << result;
}