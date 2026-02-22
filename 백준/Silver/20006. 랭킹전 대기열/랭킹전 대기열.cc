#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p, m;
vector<vector<pair<string, int>>> wq; // room1 - p1(lv, nick), p2(lv, nick)  ,,,
                                                // room2 - p1(lv, nick),,,
void search_suit_wq(string n, int l) {
    bool flag = false;
    
    for (int i = 0; i < wq.size(); i++) {
        int leader_lv = wq[i][0].second;
        bool condition = (l >= leader_lv - 10) && (l <= leader_lv + 10) && (wq[i].size() < m);
        
        if (condition) {
            wq[i].push_back({n, l});
            flag = true;
            break;
        }
    }
    
    if (!flag)
        wq.push_back({{n, l}});
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> p >> m;
    
    for (int i = 0; i < p; i++) {
        int l; string n;
        cin >> l >> n;
        
        search_suit_wq(n, l);
    }
    
    for (auto wq_ : wq) {
        sort(wq_.begin(), wq_.end());
        
        if (wq_.size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";
        
        for (auto wq__ : wq_)
            cout << wq__.second << ' ' << wq__.first << '\n';
    }
}

// wq 중 적절한 q 탐색
// 적절: 가득 차지 않음, 방장lv - 10 <= cur_lv <= 방장lv - 10