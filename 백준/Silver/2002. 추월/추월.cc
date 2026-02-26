#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    vector<string> in_car;
    map<string, int> out_car;
    set<string> cand;
    
    for (int i = 0; i < n; i++) {
        string num_car; cin >> num_car;
        in_car.push_back(num_car);
    }
    
    for (int i = 0; i < n; i++) {
        string num_car; cin >> num_car;
        out_car.insert({num_car, i});
    }
    
    for (int i = 0; i < n; i++) {
        string std = in_car[i];
        int std_idx = out_car[std];
        
        for (int j = i + 1; j < n; j++) {
            string comp = in_car[j];
            int comp_idx = out_car[comp];
            
            if (comp_idx < std_idx)
                cand.insert(comp);
        }
    }
    
    cout << cand.size();
}

// in_car 순회
// in_car[i]의 out_car idx(std_idx)와 in_car[i+1],,, 들의 out_car idx(comp_idx) 비교
// comp_idx가 std_idx보다 작다면 set에 추가

// N K D A
// A N K D

// 0K 5A 4B 6A ZF
// 5A ZF 6A 0K 4B

// 0K 5A 4B 6A ZF
// 0K 5A ZF 6A 4B

// A Q K N J
// J K A Q N