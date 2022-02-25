# 주차 요금 계산  https://programmers.co.kr/learn/courses/30/lessons/92341

from math import ceil

def solution(fees, records):
    dic = {}
    for rec in records:
        print(dic)
        time = int(rec[0:2])*60+int(rec[3:5])
        carnum = int(rec[6:10])
        # 처음 보는 차가 들어올 때
        if carnum not in dic: dic[carnum]=[0, time]
        # 이전에 있는 차가 나갈 때
        elif len(dic[carnum])==2:
            dic[carnum][0]+=(time-dic[carnum][1])  #사용시간
            dic[carnum].pop()
        else:
        #다시 들어올 때
            dic[carnum].append(time)
    for value in dic.values():
        if len(value)==2:
            value[0]+=(23*60+59-value[1])
            value.pop()
    ans = []
    for key in dic:
        fee = fees[1] if dic[key][0]<=fees[0] else fees[1]+ceil((dic[key][0]-fees[0])/fees[2])*fees[3]
        ans.append([key, fee])
    ans.sort()
    result = []
    for S in ans:
        result.append(S[1])
    return result


fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]

# solution(fees, records)


dit = {1: [1,3], 2:[2,3]}
dit[1].pop()

print(dit[1])