#include <iostream>
using namespace std;

int n;
int grid[14][14];
int arr[14];
bool visited[14];
int cnt;

bool check(int k) {
	int add = k + arr[k];
	int sub = k - arr[k];

	for (int i = 0; i < k; i++) {
		if (i + arr[i] == add || i - arr[i] == sub) {
			return false;
		}
	}

	return true;
}

void bt(int k) {
	if (k == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[k] = i;
			grid[k][arr[k]] = 1;

			if (!check(k)) {
				visited[i] = false;
				grid[k][arr[k]] = 0;
				continue;
			}

			bt(k + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	bt(0);
	cout << cnt;
}