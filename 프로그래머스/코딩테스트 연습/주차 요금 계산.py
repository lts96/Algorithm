def convert_time(s):
    hour = int(s[0:2])
    minute = int(s[3:5])
    return hour * 60 + minute

def calculate_fee(t, fees):
    if t <= fees[0]:
        return fees[1]
    ret = fees[1]
    d = int((t - fees[0]) / fees[2])
    if ((t - fees[0]) % fees[2]) != 0: 
        d += 1
    ret += (d * fees[3])
    return int(ret)

def solution(fees, records):
    answer = []
    dict = {}
    arr = {}
    flag = {}
    for s in records:
        result = 0
        list = s.split(" ")
        time = convert_time(list[0])
        num = int(list[1])
        direct = list[2]
        if direct == "IN":
            dict[num] = time
            flag[num] = False
            if (num in arr) == False:
                arr[num] = 0
        else:
            arr[num] += (time - dict[num])
            flag[num] = True
    list = []
    for i in arr: 
        if flag[i] == False:
            arr[i] += convert_time("23:59") - dict[i]
        temp = calculate_fee(arr[i], fees)
        list.append([i, temp])
    list.sort()
    for num, fee in list:
        answer.append(fee)
    return answer
