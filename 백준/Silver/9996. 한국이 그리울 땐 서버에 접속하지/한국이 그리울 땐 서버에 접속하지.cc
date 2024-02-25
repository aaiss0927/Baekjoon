#include <iostream>
#include <vector>
using namespace std;

bool accord(string str, string ptn) {    
    if (str.length() < ptn.length() - 1) {
        return false;
    }

    int idx_star = ptn.find("*");
    string part_1 = ptn.substr(0, idx_star);
    string part_2 = ptn.substr(idx_star + 1);

    int length = str.length();
    int length_1 = part_1.length();
    int length_2 = part_2.length();

    for (int i = 0; i < length_1; i++) {
        if (str[i] != part_1[i]) {
            return false;
        }
    }

    for (int i = 0; i < length_2; i++) {
        if (str[i + length - length_2] != part_2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N; cin >> N;
    string pattern; cin >> pattern;

    for (int i = 0; i < N; i++) {
        string file_name; cin >> file_name;

        if (accord(file_name, pattern)) {
            cout << "DA\n";
        }

        else {
            cout << "NE\n";
        }
    }
}