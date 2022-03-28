# 로또 최고 최저



def solution(lottos, win_nums):
    # 같은 갯수 받기 
    num = 7
    for a in lottos :
        num -= win_nums.count(a)
    answer = [num]
    num -= lottos.count(0)
    answer.insert(0, num)
    return answer

lottos = [1, 2, 3, 0, 0, 6]
win_nums = [1, 2, 3, 4, 5, 6]

print(solution(lottos, win_nums))

# 틀린 부분이 있는데 아직 못 고침 
