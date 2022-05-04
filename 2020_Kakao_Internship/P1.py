def solution(numbers, hand):
    answer = ''
    dist = [(4,2)]
    row, col = 1, 1
    for i in range(1,10):
        dist.append((row, col))
        if i%3==0:
            row+=1
            col=1
        else:
            col+=1
    dist.append((4,1))
    dist.append((4,3))
    l, r = 10, 11 
    for n in numbers:
        if n == 1 or n == 4 or n==7:
            answer+='L'
            l = n
        elif n==3 or n==6 or n==9:
            answer+='R'
            r = n
        else:
            dist_l = abs(dist[l][0]-dist[n][0])+abs(dist[l][1]-dist[n][1])
            dist_r = abs(dist[r][0]-dist[n][0])+abs(dist[r][1]-dist[n][1])
            if dist_l==dist_r:
                if hand=='left':
                    answer+='L'
                    l = n
                else:
                    answer+='R'
                    r = n
            elif dist_l<dist_r:
                answer+='L'
                l = n
            else:
                answer+='R'
                r = n
    return answer