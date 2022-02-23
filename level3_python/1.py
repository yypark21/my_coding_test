# 추석 트레픽 https://programmers.co.kr/learn/courses/30/lessons/17676?language=python3

def checktr(time, log):
    c=0
    start=time
    end=time+1000
    for i in log:
        if i[1]>=start and i[0]<end:
            c+=1
    return c

def solution(lines):
    answer = 1
    log=[]
    for line in lines:
        d, t, s = line.split()
        t=t.split(":")
        s=s.replace("s", "")
        end = (((int(t[0]) * 60  + int(t[1])) * 60 ) + (float(t[2]) ))* 1000
        start = end - float(s) * 1000 + 1
        log.append([start,end])
    for i in log:
        answer=max(answer,checktr(i[0],log),checktr(i[1],log))
    print(answer)
    return answer

lines=[
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
]

solution(lines)