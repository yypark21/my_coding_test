# [1차] 셔틀버스 https://programmers.co.kr/learn/courses/30/lessons/17678?language=python3


# 9시부터 n회 t분 최대 m명
def solution(n, t, m, timetable):
    crew=[]
    busTime = [9*60 + t*i for i in range(n)]
    for i in timetable:
        hh, mm = i.split(':')
        crew.append(int(hh)*60+int(mm))
    crew.sort()
    i = 0
    for tm in busTime:
        cnt=0
        while cnt < m and i<len(crew) and crew[i] <=tm:
            i+=1
            cnt+=1 
        answer= tm if cnt < m else crew[i-1] -1
        
    return str(answer//60).zfill(2) + ":" + str(answer%60).zfill(2)


n=2
t=10
m=5
timetable=["08:02", "08:03", "08:00", "08:01" ]
print(solution(n,t,m,timetable))