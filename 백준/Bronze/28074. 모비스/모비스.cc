#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str; cin >> str;
    int arr[5] = {0, 0, 0, 0, 0};

    for (char c : str) {
        if (c == 'M')
            arr[0]++;
        else if (c == 'O')
            arr[1]++;
        else if (c == 'B')
            arr[2]++;
        else if (c == 'I')
            arr[3]++;
        else if (c == 'S')
            arr[4]++;
    }

    if (arr[0] && arr[1] && arr[2] && arr[3] && arr[4])
        cout << "YES";
    else
        cout << "NO";
}