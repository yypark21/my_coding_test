def solution(record):
    answer = []
    list_=[]
    dic={}
    for i in range(len(record)):
        list_.append(record[i].split(' '))

    for i in range(len(list_)):
        if list_[i][0] == 'Enter':
            if list_[i][1] not in dic:
                dic[list_[i][1]]=list_[i][2]
            else :
                if dic[list_[i][1]] is not list_[i][2]:
                    dic[list_[i][1]]=list_[i][2]
        elif list_[i][0]=='Change':
            dic[list_[i][1]]=list_[i][2]

    for i in range(len(list_)):
        if list_[i][0]=='Enter':
            answer.append(dic[list_[i][1]]+"님이 들어왔습니다.")
        if list_[i][0]=='Leave':
            answer.append(dic[list_[i][1]]+"님이 나갔습니다.")
    print(answer)
    return answer

re=["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

solution(re)