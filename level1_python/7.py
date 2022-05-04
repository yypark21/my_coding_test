# https://programmers.co.kr/learn/courses/30/lessons/86051 없는 숫자 더하기

# my_code
def solution(numbers):
    number = {0,1,2,3,4,5,6,7,8,9}
    return sum(number-set(numbers))
  
# 다른 사람 
def solution(numbers):
    return 45 - sum(numbers)
