#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int find(vector<int>& p, int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p, p[x]);
}

bool uni(vector<int>& p, int u, int v) {
    u = find(p, u);
    v = find(p, v);
    
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<int> p(n + 1, -1);
        int first_set_leader, second_set_leader;
        int first_set_count, second_set_count;
        first_set_count = second_set_count = 0;
        
        for (int j = 0; j < wires.size(); j++) {
            if (j == i) continue;
            uni(p, wires[j][0], wires[j][1]);
        }
        
        first_set_leader = find(p, 1);
        for (int i = 2; i <= n; i++)
            if (find(p, i) != first_set_leader) second_set_leader = find(p, i);
        
        for (int i = 1; i <= n; i++) {
            if (find(p, i) == first_set_leader) first_set_count++;
            else second_set_count++;
        }
        
        answer = min(answer, abs(first_set_count - second_set_count));
    }
    
    return answer;
}