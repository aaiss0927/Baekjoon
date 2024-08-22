#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	while (T--) {
		string a, b; cin >> a >> b;
		int dist = 0;

		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				dist++;
		}

		cout << "Hamming distance is " << dist << ".\n";
	}
}