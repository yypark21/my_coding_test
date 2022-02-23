import re

st='absdfSVDFAsw123.'
st = re.sub('[^a]|[.]$', '', st)
print(st)


def solution(new_id):
    answer = ''
    
    for i in new_id.lower():
        if (i >= 'a' and i <='z') or (i>='0' and i<='9') or i == '.' or i == '-' or i == '_' :
            answer+=i
    while '..' in answer:
        answer=answer.replace('..','.')
    answer = answer.strip('.')
    answer = answer[0:15].strip('.')
    if answer == '':
        answer += 'a'
    if len(answer) <= 2:        
        while 1 :
            answer+=answer[-1]
            if len(answer) >= 3:
                break
    return answer



# import re

# def solution(new_id):
#     st = new_id
#     st = st.lower()
#     st = re.sub('[^a-z0-9\-_.]', '', st)
#     st = re.sub('\.+', '.', st)
#     st = re.sub('^[.]|[.]$', '', st)
#     st = 'a' if len(st) == 0 else st[:15]
#     st = re.sub('^[.]|[.]$', '', st)
#     st = st if len(st) > 2 else st + "".join([st[-1] for i in range(3-len(st))])
#     return st