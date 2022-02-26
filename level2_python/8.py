# k진수에서 소수 개수 구하기 https://programmers.co.kr/learn/courses/30/lessons/92335?language=python3

def is_prime_num(n):
    i=2
    while i*i<=n:
        if n % i == 0: return 0
        i+=1 
    return 1

def solution(n, k):
    rev_base = ''
    answer = 0
    answers = ''

    while n > 0:
        n, mod = divmod(n, k)
        rev_base += str(mod)
    
    for i in rev_base[::-1].split('0'):
        if i != '1':
            answer += is_prime_num(int(i))

    return answer


n=437674
k=3
print(solution(n,k))
