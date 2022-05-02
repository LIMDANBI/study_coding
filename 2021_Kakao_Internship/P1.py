def solution(s):
    li_word = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    answer = ""
    tmp = ""
    for i in s:
        if "0"<= i and i<="9":
            answer+=i
        else:
            tmp+=i
            if tmp in li_word:
                idx = li_word.index(tmp)
                answer+=str(idx)
                tmp = ""
    answer = int(answer)
    return answer