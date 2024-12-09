#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
        int current = q.front().first;
        int operations = q.front().second;
        q.pop();

        if (current == y) {
            return operations;
        }

        int nextValues[] = {current + n, current * 2, current * 3};
        for (int next : nextValues) {
            if (next <= y && visited.find(next) == visited.end()) {
                q.push({next, operations + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}