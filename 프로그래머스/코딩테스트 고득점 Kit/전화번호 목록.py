# 푼 방법 : 우선 전화번호를 딕셔너리에 전부 넣고 
# 전화번호를 for로 돌면서 문자열 앞부분만 (접두사니까) 자기 크기보다 작게 잘라서 검사 
# 이렇게 하면 시간복잡도는 O(n*m) 정도?  m은 문자열 길이 
def solution(phone_book):
    answer = True
    dic = {}
    temp = ""
    for num in phone_book: 
        dic[num] = 0
    for num in phone_book: 
        for i in range(0,len(num)):
            temp = num[0:i]
            if temp in dic: 
                answer = False
                return answer
    return answer
