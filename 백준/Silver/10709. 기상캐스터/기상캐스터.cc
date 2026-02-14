#include <iostream>
using namespace std;

int answer[100][100];

int main() {
	int row_size, col_size;
	cin >> row_size >> col_size;

	for (int i = 0; i < row_size; i++) {
		string row; 
		cin >> row;

		int distance_from_cloud = -1;
		bool cloud_detected = false;

		for (int j = 0; j < col_size; j++) {
			if (row[j] == 'c') {
				distance_from_cloud = 0;
				cloud_detected = true;
			}

			else if (cloud_detected) distance_from_cloud++;

			answer[i][j] = distance_from_cloud;
		}
	}

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			cout << answer[i][j] << ' ';
		}

		cout << '\n';
	}
}