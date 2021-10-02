import sys
input = sys.stdin.readline

def solution():
    stack, ans = [0], []
    begin = 1
    is_no = False
    n = int(input())
    for _ in range(n):
        is_top, is_add = False, False
        num = int(input())
        if stack[-1] == num:
            is_top = True
            ans.append("-")
            del stack[-1]
        else:
            for i in range(begin, num+1):
                is_add = True
                stack.append(i)
                ans.append("+")
            del stack[-1]
            ans.append("-")
        if num+1>begin:
            begin = num+1
        if is_top==False and is_add==False: is_no = True
    if is_no:
        print("NO")
    else:
        for i in ans: print(i)
solution()