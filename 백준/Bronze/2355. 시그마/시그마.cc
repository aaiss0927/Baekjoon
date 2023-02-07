#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B;
	cin >> A >> B;
	
	long long minimum = min(A, B);
	long long maximum = max(A, B);
	long long sum = ((minimum + maximum) * (maximum - minimum + 1)) / 2;
	cout << sum;
}