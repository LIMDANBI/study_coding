N = input()
arrN = []
ans = str()
for i in N:
    arrN.append(int(i))
arrN.sort(reverse=True)
for i in arrN:
    ans = ans + str(i)
print(ans)