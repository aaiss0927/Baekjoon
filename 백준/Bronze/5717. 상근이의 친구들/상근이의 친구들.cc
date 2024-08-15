#include <iostream>
using namespace std;

int main() {
	while (1) {
		int m, f; cin >> m >> f;
		if (m == 0 && f == 0)
			break;
		cout << m + f << '\n';
	}
}