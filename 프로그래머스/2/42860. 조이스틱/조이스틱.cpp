#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1; // 기본: 순방향 이동

    for (int i = 0; i < len; i++) {
        // 1. 상하 조작 (알파벳 맞추기)
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 2. 좌우 조작 (커서 이동 최적화)
        int next = i + 1;
        // 연속된 A의 끝을 찾음
        while (next < len && name[next] == 'A') next++;

        // (i만큼 갔다가 돌아오는 경로) vs (뒤쪽부터 갔다가 돌아오는 경로)
        int move_forward_back = i + i + (len - next);
        int move_backward_first = (len - next) * 2 + i;
        
        move = min({move, move_forward_back, move_backward_first});
    }

    return answer + move;
}