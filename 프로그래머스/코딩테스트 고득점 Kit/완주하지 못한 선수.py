def solution(participant, completion):
    answer = ''
    d = dict()
    for name in participant: 
        if name in d: 
            d[name] += 1 
        else :
            d[name] = 1 
    for name in completion: 
        d[name] -= 1
    for name in d: 
        if d[name] > 0:
            answer = name
            break
    return answer
