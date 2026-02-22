#include <iostream>
#include <unordered_map>
using namespace std;

int k, l;
unordered_map<string, int> m;
unordered_map<int, string> m_rev;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> k >> l;
    
    int cur = 1;
    
    for (int i = 0; i < l; i++) {
        string id; cin >> id;
        
        if (m[id] != 0)
            m_rev[m[id]] = "";
        
        m[id] = cur;
        m_rev[cur] = id;
        cur++;
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= l; i++) {
        if (m_rev[i] != "") {
            cout << m_rev[i] << '\n';
            cnt++;
        }
        
        if (cnt == k) break;
    }
}