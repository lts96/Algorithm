from sys import stdin

# 배수를 쉽게 판별하는 방법 -> 각 자리수를 모두 더해서 내가 찾는 배수가 되는지 체크해본다 
# 위키 -> 배수 판별법 참고 
def solution(number):
    answer = ''
    list = []
    sum = 0
    zero_cnt = 0
    for i in range(0, len(number)):
        temp = int(number[i])
        list.append(temp)
        sum += temp
        if temp == 0:
            zero_cnt += 1
    if sum % 3 != 0 or zero_cnt == 0:
        answer = "-1"
    else:
        new_list = sorted(list, reverse=True)
        for i in new_list:
            answer += str(i)
    return answer


if __name__ == "__main__":
    number = stdin.readline().rstrip('\n')
    print(solution(number))
