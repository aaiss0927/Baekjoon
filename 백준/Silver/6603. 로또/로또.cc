#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void search(int idx, vector<int> num) {
	if (idx == num.size() - 1) {
		if (arr.size() == 6) {
			for (int i = 0; i < arr.size(); i++) {
				cout << arr[i] << " ";
			}
			cout << '\n';
		}
		return;
	}
	else {
		arr.push_back(num[idx + 1]);
		search(idx + 1, num);
		arr.pop_back();
		search(idx + 1, num);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	do {
		cin >> k;
		vector<int> num(k);
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		search(-1, num);
		cout << '\n';
	} while (k != 0);	
}