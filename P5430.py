T = int(input())
for i in range(T):
    is_error=0
    is_reverse=0
    p = input()
    n = int(input())
    str_list = input()
    str_list = str_list[1: -1]
    n_list = []
    if n!=0:
        n_list = list(map(int, str_list.split(',')))

    for i in p:
        if i=='R':
            is_reverse+=1
        else:
            if n==0:
                is_error=1
                break
            if is_reverse%2:
                del n_list[-1]
            else:
                del n_list[0]
            n-=1
    if is_error:
        print("error")
    else:
        print('[', end='')
        if is_reverse % 2:
            for i in range(len(n_list) - 1, -1, -1):
                if i == len(n_list) - 1:
                    print(n_list[i], end='')
                else:
                    print(',', n_list[i], sep='', end='')
        else:
            for i in range(len(n_list)):
                if i == 0:
                    print(n_list[i], end='')
                else:
                    print(',', n_list[i], sep='', end='')
        print(']')