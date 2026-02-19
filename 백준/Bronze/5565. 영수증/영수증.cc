#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int total; cin >> total;

	for (int i = 0; i < 9; i++) {
		int price; cin >> price;
		total -= price;
	}

	cout << total;
}