#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(tuple<string, int, int, int> t1, tuple<string, int, int, int> t2) {
    string name1, name2;
    int k1, k2, e1, e2, m1, m2;
    tie(name1, k1, e1, m1) = t1;
    tie(name2, k2, e2, m2) = t2;
    
    if (k1 == k2) {
        if (e1 == e2) {
            if (m1 == m2)
                return name1 < name2;
            
            return (m1 > m2);
        }
        
        return (e1 < e2);
    }
    
    return (k1 > k2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    vector<tuple<string, int, int, int>> v;
    
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        int k, e, m; cin >> k >> e >> m;
        v.push_back({name, k, e, m});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < n; i++)
        cout << get<0>(v[i]) << '\n';
}