e_s = []
temp1 = []
sum = 0
for i in range(8):
    s = int(input())
    e_s.append(s)
temp1 = e_s[:]
for i in range(3):
    temp1.remove(min(temp1))
for i in temp1:
    sum += i
print(sum)
for i in temp1:
    print(e_s.index(i)+1,end=' ')