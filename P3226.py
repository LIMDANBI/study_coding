N = int(input())
ans = 0
for i in range(N):
    line = input()
    H = int(line[0:2])
    M = int(line[3:5])
    D = int(line[6:])
    end_H, end_M = H, M

    if M+D<60:
        end_M = M+D
    else :
        Q, end_M = (M+D)//60, (M+D)%60
        if H+Q < 24:
            end_H = H+Q
        else:
            end_H = (H+Q)%24
    if H == 6 and end_H == 7:
        ans += (D-end_M)*5 + end_M*10
    elif H == 18 and end_H == 19:
        ans += (D-end_M)*10 + end_M*5
    else:
        if 6 < H < 19:
            ans += 10*D
        else:
            ans += 5*D
print(ans)