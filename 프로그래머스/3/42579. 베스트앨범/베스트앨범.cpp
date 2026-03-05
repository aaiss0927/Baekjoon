#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0]) {
        if (v1[1] == v2[1]) return v1[2] < v2[2];
        return v1[1] > v2[1];
    }
    return v1[0] > v2[0];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    unordered_map<string, int> total_plays;
    unordered_map<string, int> genres_cnt;
    vector<vector<int>> v = vector<vector<int>> (n, vector<int>(3));
    
    for (int i = 0; i < n; i++) total_plays[genres[i]] += plays[i];
    for (int i = 0; i < n; i++) v[i] = {total_plays[genres[i]], plays[i], i};
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        int total_plays, plays, idx;
        total_plays = v[i][0];
        plays = v[i][1];
        idx = v[i][2];
        
        if (genres_cnt[genres[idx]] >= 2) continue;
        
        genres_cnt[genres[idx]]++;
        answer.push_back(idx);
    }
    
    return answer;
}

// 베스트 앨범에 들어갈 노래의 인덱스들
// m["classic"] = 1450
// m["pop"] = 3100

// {재생 횟수 합, 장르}로 정렬
// {재생 횟수, 고유 번호}로 정렬
// {재생 횟수 합, 재생 횟수, 고유번호}