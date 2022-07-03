def solution(array, commands):
    answer = []
    for c in range(len(commands)):
        i = commands[c][0]
        j = commands[c][1]
        k = commands[c][2]
        sub = array[i-1:j]
        sub.sort()
        answer.append(sub[k-1])
    return answer