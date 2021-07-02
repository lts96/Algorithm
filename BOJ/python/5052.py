import sys

"""
입력을 input에서 readline으로 바꾸니까 안들어가야될 개행문자가 들어가서 
계속 오답이 나왔던 것 
"""
def solution(phone_book):
    answer = True
    dic = {}
    for num in phone_book:
        dic[num] = 0
    for num in phone_book:
        if len(num) == 1:
            continue
        for i in range(1,len(num)):
            temp = num[0:i]
            if temp in dic and temp != num:
                answer = False
                return answer
    return answer

if __name__ == "__main__":
    t = int(input())
    for i in range(0,t):
        n = int(input())
        list = []
        for j in range(0,n):
            temp = sys.stdin.readline()
            list.append(temp.rstrip("\n"))
        result = solution(list)
        if result == True:
            print("YES")
        else:
            print("NO")
