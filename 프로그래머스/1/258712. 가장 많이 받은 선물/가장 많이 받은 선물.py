from collections import defaultdict

# 다음 달에 가장 선물을 많이 받은 사람이 받은 선물의 수

# 1. 두 사람이 선물 주고받은 기록이 있는 경우
# hist["muzi"]["ryan"] = 3
# -- 더 많이 준 사람이 하나 받기

# 2. 기록 없거나 주고받은 수가 같은 경우
# score["muzi"] = 3
# -- 선물 지수가 더 큰 사람이 받기

# 3. else) continue

# 모든 pair에 대해 1, 2, 3에 따라 처리
# gifts "A B" : A -> B 선물 
# dict에 선물 받은 기록 저장: d = {"muzi" : ["ryan", "ryan", "ryan", "frodo", "neo"]}

def solution(friends, gifts):
    answer = 0
    hist = defaultdict(list)
    hist_num = defaultdict(dict)
    score = {}
    next_get = {}
    
    for g in gifts:
        a, b = g.split()
        hist[b].append(a)
        
    for i in range(len(friends)):
        b = friends[i]
        
        for j in range(len(friends)):
            if i == j: continue
            
            a = friends[j]
            hist_num[b][a] = hist[b].count(a)

    for i in range(len(friends)):
        b = friends[i]
        score[b] = -len(hist[b])
        next_get[b] = 0
        
        for j in range(len(friends)):
            if i == j: continue
            
            a = friends[j]
            score[b] += hist_num[a][b]
        
    for i in range(len(friends)):
        for j in range(i + 1, len(friends)):
            b, a = friends[i], friends[j]
            
            if ((hist_num[b][a] > 0) or (hist_num[a][b] > 0)) and (hist_num[b][a] != hist_num[a][b]):
                if hist_num[b][a] > hist_num[a][b]: next_get[a] += 1
                else: next_get[b] += 1
            
            elif ((hist_num[b][a] == 0) and (hist_num[a][b] == 0)) or (hist_num[b][a] == hist_num[a][b]):
                if score[a] > score[b]: next_get[a] += 1
                elif score[a] < score[b]: next_get[b] += 1
    
    for v in next_get.values():
        if v > answer: answer = v
            
    return answer