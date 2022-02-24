# 크레인 인형 뽑기 https://programmers.co.kr/learn/courses/30/lessons/64061?language=python3
def solution(board, moves):
    answers=[0]
    answer=0
    for n in moves:
        for i in range(len(board)):
            if board[i][n-1] != 0: 
                answers.append(board[i][n-1])
                board[i][n-1]=0
                
                if answers[-1]==answers[-2]:
                    answers.pop(-1)
                    answers.pop(-1)
                    answer+=2
                break
    return answer

board=[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves=[1,5,3,5,1,2,1,4]

print(solution(board, moves))