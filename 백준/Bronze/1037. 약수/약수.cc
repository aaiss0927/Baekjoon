#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	int num;
	vector<int> arr;
	while (N--) {
		cin >> num;
		arr.push_back(num);
	}

	int min = *min_element(arr.begin(), arr.end());
	int max = *max_element(arr.begin(), arr.end());
	cout << min * max;
}