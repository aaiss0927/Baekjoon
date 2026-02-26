#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    map<string, set<string>> groups;
    
    for (int i = 0; i < n; i++) {
        string team_name;
        int num;
        cin >> team_name >> num;
        
        for (int j = 0; j < num; j++) {
            string name; cin >> name;
            groups[team_name].insert(name);
        }
    }
    
    for (int i = 0; i < m; i++) {
        string cmd; cin >> cmd;
        int type; cin >> type;
        
        if (type == 0) {
            for (auto member : groups[cmd])
                cout << member << '\n';
        }
        
        else {
            for (auto group : groups) {
                if (group.second.find(cmd) != group.second.end()) {
                    cout << group.first << '\n';
                    break;
                }
            }
        }
    }
}