n = input()
ans = 0
for i in range(max(1, int(n)-54), int(n)):
    tmp = i
    for j in range(len(str(i))):
        tmp+=int(str(i)[j])
    if tmp==int(n):
        ans = i
        break
print(ans)