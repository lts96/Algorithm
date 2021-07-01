def solution(genres, plays):
    answer = []
    dic,cnt = {}, {}
    
    # 우선 어떤 장르가 제일 재생 합계가 많은지 계산
    temp = 0
    for key, value in zip(genres, plays): 
        if key in cnt: 
            cnt[key] += value
        else :
            cnt[key] = value
    s_cnt = sorted(cnt.items(), key=lambda x: x[1], reverse=True)
    
    
    i = 0
    for key, value in zip(genres, plays): 
        if key in dic: 
            dic[key].append([value, -1 * i])
        else :
            dic[key] = []
            dic[key].append([value, -1 * i])
        i+=1
    
    #s_cnt에서 많이 재생된 장르 이름 순서대로 뽑아서 dic에 저장된 결과를 조회
    # -1 곱해준 것은 정렬 순서에서 재생횟수 같으면 인덱스 적은 순으로 정렬하기 위해서 
    for key, value in s_cnt: 
        list = sorted(dic[key], reverse = True)
        if len(list) >= 2: 
            answer.append(-1 * list[0][1])
            answer.append(-1 * list[1][1])
        elif len(list) == 1: 
            answer.append(-1 * list[0][1])
    return answer
