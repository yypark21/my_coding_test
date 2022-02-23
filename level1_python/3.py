# 숫자 문자열과 영단어 https://programmers.co.kr/learn/courses/30/lessons/81301?language=python3

def solution(s):
    a = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    for i in a:
        s = s.replace(i,str(a.index(i)))
    return int(s)



num_dic = {"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}

def solution(s):
    answer = s
    for key, value in num_dic.items():
        answer = answer.replace(key, value)
    return int(answer)