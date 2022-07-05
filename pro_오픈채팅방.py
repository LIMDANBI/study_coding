def solution(record):
    answer = []
    tmp = []
    user = {}
    for r in record:
        splited = r.split(" ")
        if splited[0]=="Enter":
            user[splited[1]] = splited[2]
            tmp.append(splited[1] + " enter")
        elif splited[0]=="Leave":
            tmp.append(splited[1] + " leave")
        else: # Change
            user[splited[1]] = splited[2]
    for t in tmp:
        splited = t.split()
        uid = splited[0]
        cmd = splited[1]
        if cmd == "enter":
            answer.append(user[uid]+"님이 들어왔습니다.")
        else:
            answer.append(user[uid]+"님이 나갔습니다.")
    return answer