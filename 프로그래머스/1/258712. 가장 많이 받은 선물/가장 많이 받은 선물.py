# hist : 2차원 배열
# name_to_idx : {name : i for i, name in enumerate(friends)}

# hist[giver][taker]
#        muzi ryan frodo neo  
# muzi    0    0
# ryan    
# frodo
# neo

def solution(friends, gifts):
    n = len(friends)
    hist = [[0] * n for _ in range(n)]   # hist[giver][taker]
    score = [0] * n
    next_get = [0] * n
    name_to_idx = {name : i for i, name in enumerate(friends)}
    
    for g in gifts:
        giver, taker = g.split()
        idx_g, idx_t = name_to_idx[giver], name_to_idx[taker]
        
        hist[idx_g][idx_t] += 1
        score[idx_g] += 1
        score[idx_t] -= 1
        
    for i in range(len(friends)):
        for j in range(i + 1, len(friends)):            
            if hist[i][j] > hist[j][i]: next_get[i] += 1
            elif hist[i][j] < hist[j][i]: next_get[j] += 1
            else:
                if score[i] > score[j]: next_get[i] += 1
                elif score[i] < score[j]: next_get[j] += 1
                
    return max(next_get)