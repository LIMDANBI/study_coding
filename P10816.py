N = int(input())
card = list(map(int, input().split()))
M = int(input())
sg_have = list(map(int, input().split()))

card_count = dict()
for i in card:
    if i in card_count:
        card_count[i]+=1
    else:
        card_count[i]=1
for i in sg_have:
    if i in card_count:
        print(card_count[i], end=' ')
    else:
        print(0, end=' ')