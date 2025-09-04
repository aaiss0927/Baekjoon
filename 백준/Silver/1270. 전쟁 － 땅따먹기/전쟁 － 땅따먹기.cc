#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		unordered_map<long long, int> m;
		bool flag = false;

		for (int j = 0; j < t; j++) {
			long long num; cin >> num;

			if (flag)
				continue;

			m[num]++;

			if ((t / 2) < m[num]) {
				cout << num << '\n';
				flag = true;
			}
		}
		
		if (!flag)
			cout << "SYJKGW\n";
	}
}