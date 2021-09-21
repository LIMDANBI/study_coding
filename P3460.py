T = int(input())
for i in range(T):
    binary_number = []
    n = int(input())
    while n>=2:
        binary_number.append(n%2)
        n//=2
    binary_number.append(n)
    for i in range(len(binary_number)):
        if binary_number[i]==1:
            print(i, end=' ')