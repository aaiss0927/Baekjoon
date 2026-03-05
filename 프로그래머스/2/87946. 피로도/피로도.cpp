#include <string>
#include <vector>
using namespace std;

bool is_visited[8];
vector<int> v;

void bt(int k, vector<vector<int>> dungeons, int target_len, int& answer) {
    if (v.size() == target_len) {
        if (target_len > answer) answer = target_len;
        return;
    }
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (is_visited[i]) continue;
        if (k < dungeons[i][0]) continue;
        
        v.push_back(i);
        is_visited[i] = true;
        bt(k - dungeons[i][1], dungeons, target_len, answer);
        is_visited[i] = false;
        v.pop_back();
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    for (int i = dungeons.size(); i > 0; i--)
        bt(k, dungeons, i, answer);
    
    return answer;
}

// 피로도 >= 0
// 최소 필요 피로도, 소모 피로도
// k: 현재 피로도  /  1 <= k <= 5000
// dungeons: {{최소 필요 피로도, 소모 피로도}, ,,, ,}
// 1 <= dungeons.size() <= 8  /  1 <= 최소 필요 피로도 <= 소모 피로도 <= 1000
// dungeons[i] = dungeons[j] 가능
// result: 유저가 탐험할 수 있는 최대 던전 수
// k >= 최소 필요 피로도인 경우 탐험 가능
// 백트래킹 완탐