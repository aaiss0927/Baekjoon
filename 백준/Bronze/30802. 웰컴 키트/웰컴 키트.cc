#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> t_num(6);

	for (int i = 0; i < 6; i++)
		cin >> t_num[i];

	int t, p;
	cin >> t >> p;

	int t_sum = 0;
	
	for (int i = 0; i < 6; i++)
		t_sum += ceil((double)(t_num[i]) / t);

	cout << t_sum << '\n';
	cout << n / p << ' ' << n % p;
}