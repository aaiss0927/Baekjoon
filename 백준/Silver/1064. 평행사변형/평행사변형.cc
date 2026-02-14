#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double l2_norm(int xa, int ya, int xb, int yb) {
	return sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	if (((xa-xb)*(ya-yc)) == ((ya-yb)*(xa-xc))) {
		cout << -1.0;
		return 0;
	}

	double s1 = l2_norm(xa, ya, xb, yb) + l2_norm(xb, yb, xc, yc);
	double s2 = l2_norm(xb, yb, xc, yc) + l2_norm(xc, yc, xa, ya);
	double s3 = l2_norm(xc, yc, xa, ya) + l2_norm(xa, ya, xb, yb);

	vector<double> v = { s1, s2, s3 };
	double gap = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
	
	cout << fixed;
	cout.precision(9);
	cout << 2 * gap;
}