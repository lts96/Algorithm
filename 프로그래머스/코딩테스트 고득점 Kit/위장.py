# 조합의 공식이 간단함 -> 너무 어렵게 생각해서 못품 
# 각 의상 종류 카운트에 +1을 해주고 곱한다음 하나도 입지 않은 경우 nC0 = 1을 빼주면 끝 
# 각 의상 종류를 카운트하고 1을 더하는 이유는 해당 의상을 아예 입지 않는 경우를 고려하기 때문 
# 예제 1의 경우 (2 + 1) * (1 + 1) - 1 (어떤 옷도 안입는 경우)
# 조합에 대한 이해가 부족 -> 연습하기 
def solution(clothes):
    answer = 0
    dic = {}
    for key, value  in clothes: 
        dic[key] = value
    list = dic.values()
    
    part = {}
    for name in list : 
        if name in part: 
            temp = part[name] + 1
            part[name] = temp
        else: 
            part[name] = 1
    
    temp = 1 
    for i in part.values(): 
        temp *= (i+1)
    answer += temp
    return answer-1
