#include <vector>
#include <algorithm>
#include <set> // 다음 노드를 관리하기 위해 set을 사용합니다.
#include <iostream>
using namespace std;

// 트리의 연결 관계를 저장할 인접 리스트
vector<int> adj[17];
// 각 노드의 양/늑대 정보를 저장
vector<int> g_info;
// 모을 수 있는 최대 양의 수를 저장
int max_sheep = 0;

// DFS 백트래킹 함수
// current_node: 현재 방문 중인 노드
// sheep_count: 현재까지 모은 양의 수
// wolf_count: 현재까지 모은 늑대의 수
// next_nodes: 현재까지 방문한 모든 노드의 자식들 중 아직 방문하지 않은 노드들 (후보 집합)
void dfs(int cur, int sheep_cnt, int wolf_cnt, vector<int> next_nodes) {
    
    // 현재 노드의 양/늑대 정보를 반영합니다.
    if (g_info[cur] == 0) { // 양인 경우
        sheep_cnt++;
    } else { // 늑대인 경우
        wolf_cnt++;
    }

    // 늑대 >= 양 이면 양이 모두 잡아먹히므로, 이 경로는 무효합니다.
    if (wolf_cnt >= sheep_cnt) {
        return;
    }

    // 최대 양의 수를 갱신합니다.
    max_sheep = max(max_sheep, sheep_cnt);

    // 앞으로 방문할 수 있는 노드 후보 집합을 업데이트합니다.
    // 1. 현재 노드의 자식들을 후보에 추가합니다.
    for (int child : adj[cur]) {
        next_nodes.push_back(child);
    }
    
    // 2. 이제 next_nodes에 있는 모든 노드들을 다음 방문 대상으로 시도합니다.
    // 백트래킹을 위해 for 루프 내에서 임시로 next_nodes를 수정합니다.
    for (int i = 0; i < next_nodes.size(); ++i) {
        
        // 다음에 방문할 노드를 선택합니다.
        int next_node = next_nodes[i];
        
        // 다음 탐색을 위해 현재 선택된 노드를 후보 집합에서 임시로 제거합니다.
        vector<int> temp_next_nodes = next_nodes;
        temp_next_nodes.erase(temp_next_nodes.begin() + i);
        
        // 재귀 호출을 통해 다음 탐색을 진행합니다.
        dfs(next_node, sheep_cnt, wolf_cnt, temp_next_nodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    // 전역 변수 초기화
    g_info = info;
    
    // 1. 트리 구조 구축 (인접 리스트)
    for (const auto& edge : edges) {
        int parent = edge[0];
        int child = edge[1];
        adj[parent].push_back(child);
    }
    
    // 2. DFS 시작 (루트 노드 0에서 시작)
    // 초기 상태: 
    // - current_node: 0 (루트 노드)
    // - sheep_count: 0 (함수 내부에서 0번 노드 방문 처리)
    // - wolf_count: 0 (함수 내부에서 0번 노드 방문 처리)
    // - next_nodes: {} (0번 노드의 자식들은 함수 내부에서 추가됨)
    dfs(0, 0, 0, {});
    
    return max_sheep;
}