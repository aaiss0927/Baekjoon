#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	int N;
	while (T--) {
		cin >> N;
		vector<int> arr;
		int num;
		while (N--) {
			cin >> num;
			arr.push_back(num);
		}
		cout << *min_element(arr.begin(), arr.end()) << ' '
			<< *max_element(arr.begin(), arr.end()) << '\n';
	}
}