#include <iostream>
#include <vector>
using namespace std;

vector<int> apple_cells;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;
	int j; cin >> j;

	while (j--) {
		int apple_cell; cin >> apple_cell;
		apple_cells.push_back(apple_cell);
	}

	int bucket_left = 1;
	int bucket_right = bucket_left + m - 1;
	int dist = 0;

	for (int i = 0; i < apple_cells.size(); i++) {
		if (apple_cells[i] > bucket_right) {
			int gap = apple_cells[i] - bucket_right;
			dist += gap;
			bucket_left += gap;
			bucket_right += gap;
		}

		else if (apple_cells[i] < bucket_left) {
			int gap = bucket_left - apple_cells[i];
			dist += gap;
			bucket_left -= gap;
			bucket_right -= gap;
		}
	}

	cout << dist;
}