#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    map<string, int> file_group_by_extension;
    
    for (int i = 0; i < n; i++) {
        string file_name; cin >> file_name;
        string extension = "";
        bool flag = false;
        
        for (auto c : file_name) {
            if (flag)
                extension += c;
            
            if (c == '.') flag = true;
        }
        
        file_group_by_extension[extension]++;
    }
    
    for (auto m : file_group_by_extension)
        cout << m.first << ' ' << m.second << '\n';
}