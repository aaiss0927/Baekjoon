#include <string>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool visited[8];

void bt(int k, vector<vector<int>> dungeons, int& answer) {
    if (v.size() == n) {
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (k >= dungeons[v[i]][0]) {
                k -= dungeons[v[i]][1];
                cnt++;
            }
        }
        
        answer = max(answer, cnt);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        v.push_back(i);
        bt(k, dungeons, answer);
        v.pop_back();
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    n = dungeons.size();
    bt(k, dungeons, answer);
    return answer;
}

// 0 1 2
// 0 2 1
// 1 0 2
// 1 2 0
// 2 0 1
// 2 1 0