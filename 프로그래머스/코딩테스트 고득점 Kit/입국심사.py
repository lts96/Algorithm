# 백준에 똑같은 이름의 문제 있음 
# 시간을 기준으로 파라메트릭 서치하면 끝 
def passed(time ,arr):
    cnt = 0
    temp = 0
    for i in arr: 
        temp = int(time / i)
        cnt += temp
    return cnt

def solution(n, times):
    times.sort()
    answer = 999999999999999999
    
    left, right, mid = 0, times[-1] * n, 0
    while left <= right: 
        mid = int((left + right) / 2) 
        result = passed(mid, times)
        if result >= n: 
            answer = mid
            right = mid-1
        else :
            left = mid + 1
    return answer
