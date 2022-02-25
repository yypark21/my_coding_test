# 양과 늑대 https://programmers.co.kr/learn/courses/30/lessons/92343?language=python3

def numsheep(intree):
    global ninfo
    sheep = 0
    wolf = 0
    for ele in intree:
        if ninfo[ele]==0: sheep+=1
        else: wolf+=1
    if wolf>=sheep: return 0
    return sheep

def solve(intree):
    global ans, nedges
    adjtree = []
    for ele in intree:
        for edge in nedges:
            if ele == edge[0]:
                if edge[1] not in intree: adjtree.append(edge[1])
            elif ele == edge[1]:
                if edge[0] not in intree: adjtree.append(edge[0])
    print(intree)
    num = numsheep(intree)
    if num>0:
        ans = max(ans, num)
        for ele in adjtree:
            solve(intree+[ele])

def solution(info, edges):
    global ans, nedges, ninfo
    nedges = edges[:]
    ninfo = info[:]
    ans = 0
    solve([0])
    return(ans)

info = [0,0,1,1,1,0,1,0,1,0,1,1]
edges = [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]

solution(info, edges)