def solution(n):
    answer=''
    while n>0:
        n,b= divmod(n-1,3)
        answer="124"[b]+answer 
    return answer
