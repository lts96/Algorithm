# 왜 시간초과가 될까?  100000 이하 숫자가 아니라 100000 "자리" 이하인 숫자 
# 문자열이 엄청 길어서 단순 n^2은 안됨 
def solution(number, k):
    answer = ''
    cnt = 0
    # 내 뒤의 숫자가 나보다 크면 내가 제거됨
    pos = 0
    j= 0
    
    # 문자를 제거하고나서 무조건 맨첨으로 가는게 아니라 바로 앞 부분 인덱스로 이동해서 거기서부터 다시 진행 
    # 이래야 O(n) 정도에 통과 
    while j < k:
        for i in range(pos, len(number)-1):
            if int(number[i]) < int(number[i+1]): 
                number = number[:i] + number[i+1:]
                cnt += 1
                if i == 0:
                    pos = i
                else :
                    pos = i-1
                break
        j+=1
            

    if cnt == k:
        answer = number
    else :  # 같은 숫자가 반복되거나 숫자가 내림차순일 경우 무조건 뒷자리 제거하면 됨 
        answer = number[:len(number)-(k-cnt)]
    return answer
