list_one_to_thousand = [i for i in range(1001)]
list_one_to_thousand[1]=0
for i in range(2, 1001):
    if list_one_to_thousand[i]!=0:
        for j in range(2, 501):
            remove = i*j
            if(remove<=1000):
                list_one_to_thousand[remove] = 0
            else:
                break
N = int(input())
input_list = list(map(int, input().split()))
ans = 0
for tmp in input_list:
    if list_one_to_thousand[tmp]!=0:
        ans+=1
print(ans)