# 동굴탐험 ------------
from collections import deque
import sys
sys.setrecursionlimit(1000000)

def find_cycle(start, parents, visited, recStack):
    visited[start] = True
    recStack[start] = True

    for next_node in parents[start]:
        if not visited[next_node]:
            if find_cycle(next_node, parents, visited, recStack):
                return True
        elif recStack[next_node]:
            return True

    recStack[start] = False
    return False

def solution(n, path, order):
    answer = True

    graph = [[] for _ in range(n)]

    for a, b in path:
        graph[a].append(b)
        graph[b].append(a)

    q = deque()
    q.append(0)
    visited = [False] * n
    visited[0] = True
    parents = [[] for _ in range(n)]

    while q:
        node = q.popleft()

        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                q.append(next_node)
                parents[next_node].append(node)
                # 모든 경로를 q에 쌓는다
    for parent, child in order:
        parents[child].append(parent)

    visited = [False] * n
    recStack = [False] * n

    for i in range(n):
        if not visited[i]:
            if find_cycle(i, parents, visited, recStack):
                return False

    return answer