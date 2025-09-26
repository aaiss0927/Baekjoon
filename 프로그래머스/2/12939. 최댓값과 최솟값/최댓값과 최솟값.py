def solution(s):
    answer = ''
    
    v = s.split()
    v = [int(i) for i in v]
    v.sort()
    
    answer += str(min(v)) + ' ' + str(max(v))
    
    return answer