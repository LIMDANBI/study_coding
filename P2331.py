n = input()
ans = 0
for i in range(int(n)):
    tmp = i
    for j in range(len(str(i))):
        tmp+=int(str(i)[j])
    if tmp==int(n):
        ans = i
        break
print(ans)