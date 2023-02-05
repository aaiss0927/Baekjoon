#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int current_hour, current_minute, current_second;
	int begin_hour, begin_minute, begin_second;

	cin >> current_hour;
	cin.ignore(1, ':');
	cin >> current_minute;
	cin.ignore(1, ':');
	cin >> current_second;

	cin >> begin_hour;
	cin.ignore(1, ':');
	cin >> begin_minute;
	cin.ignore(1, ':');
	cin >> begin_second;

	int hour, minute, second;

	if (begin_second - current_second >= 0) {
		second = begin_second - current_second;
	}
	else {
		second = begin_second - current_second + 60;
		begin_minute--;
	}

	if (begin_minute - current_minute >= 0) {
		minute = begin_minute - current_minute;
	}
	else {
		minute = begin_minute - current_minute + 60;
		begin_hour--;
	}

	if (begin_hour - current_hour >= 0) {
		hour = begin_hour - current_hour;
	}
	else {
		hour = begin_hour - current_hour + 24;
	}

	cout << setw(2) << setfill('0') << hour << ':';
	cout << setw(2) << setfill('0') << minute << ':';
	cout << setw(2) << setfill('0') << second;
}