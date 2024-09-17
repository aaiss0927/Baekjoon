#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int w, h; cin >> w >> h;
	double result = double(w) / 2 * h;
	cout << fixed << setprecision(1) << result;
}