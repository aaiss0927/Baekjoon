def solution(s):
    answer = ''
    
    v = list(map(int, s.split()))    
    answer += str(min(v)) + ' ' + str(max(v))
    
    return answer