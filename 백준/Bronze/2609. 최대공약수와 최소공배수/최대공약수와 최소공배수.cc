#include <iostream>
using namespace std;

int get_gcd(int, int);
int get_lcm(int, int);

int main()
{
	int a, b;
	cin >> a >> b;
	cout << get_gcd(a, b) << '\n' << get_lcm(a, b);
	return 0;
}

int get_gcd(int a, int b)
{
	return b != 0 ? get_gcd(b, a % b) : a;
}
int get_lcm(int a, int b)
{
	return a * b / get_gcd(a, b);
}