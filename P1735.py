preM = []
preF = []
for i in range(2):
    fraM, fraF = map(int, input().split())
    preM.append(fraM)
    preF.append(fraF)
ans1 = preM[1]*preF[0] + preM[0]*preF[1]
ans2 = preF[0]*preF[1]
m, n = ans1, ans2
while m%n != 0:
    m, n = n, m%n
print(ans1//n, ans2//n)