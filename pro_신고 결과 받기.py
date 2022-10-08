def solution(id_list, report, k):
    
    lenIdList = len(id_list)
    id_to_num = {} # string to int
    
    answer = [0 for _ in range(lenIdList)]
    cnt = [0 for _ in range(lenIdList)] # 신고 당한 횟수 
    isDeclaration = [[0 for _ in range(lenIdList)] for _ in range(lenIdList)] # isDeclaration[a][b] : a가 b를 신고

    num = 0
    for id in id_list:
        id_to_num[id] = num
        num+=1
    
    for r in report:
        id_a, id_b = r.split(' ') # 이용자id 신고한id
        num_a, num_b = id_to_num[id_a], id_to_num[id_b]
        if isDeclaration[num_a][num_b]==0:
            cnt[num_b]+=1
        isDeclaration[num_a][num_b] = 1
    
    for b in range(lenIdList):
        if cnt[b]>=k:
            for a in range(lenIdList):
                if isDeclaration[a][b]:
                    answer[a]+=1
    return answer