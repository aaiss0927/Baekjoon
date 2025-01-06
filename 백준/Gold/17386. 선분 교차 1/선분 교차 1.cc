#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll temp = (x2 * y3 + x3 * y1 + x1 * y2) - (x3 * y2 + x1 * y3 + x2 * y1);

	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd <= 0 && cda * cdb <= 0)
		cout << 1;
	else
		cout << 0;
}