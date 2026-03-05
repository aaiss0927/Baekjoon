#include <string>
#include <vector>
#include <cmath>
using namespace std;

void solve(int b, int y, vector<int>& answer) {
    int w, h;
    
    w = (((b / 2) + 2) + sqrt(pow(((b / 2) + 2), 2) - 4*(y + b))) / 2;
    h = (((b / 2) + 2) - sqrt(pow(((b / 2) + 2), 2) - 4*(y + b))) / 2;
    answer = {w, h};
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    solve(brown, yellow, answer);    
    return answer;
}

// 8 <= brown <= 5000 / 1 <= yellow <= 2000000
// w >= h
// brown: 테두리 한줄 격자 수 / yellow: 나머지 격자 수
// brown = 2w + 2h - 4    => w + h = (brown+4) / 2
// yellow = area - brown = wh - 2w - 2h + 4    => wh = yellow + brown
// h = (brown+4)/2 - w
// w(brown+4)/2 - w^2 = yellow + brown
// w^2 - w(brown+4)/2 + (yellow+brown) = 0
// w^2 - (0.5b+2)w + (y+b) = 0
// w = ((0.5b+2) - (((0.5b+2)^2 - 4(y+b))^0.5) / 2
// h = ((0.5b+2) + (((0.5b+2)^2 - 4(y+b))^0.5) / 2