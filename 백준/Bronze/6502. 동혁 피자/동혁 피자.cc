#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int idx = 1;

	while (1) {
		int r; cin >> r;
		
		if (!r)
			break;

		cout << "Pizza " << idx;

		int w, l; cin >> w >> l;

		if (4 * r * r < w * w + l * l)
			cout << " does not fit on the table.\n";

		else
			cout << " fits on the table.\n";

		idx++;
	}
}