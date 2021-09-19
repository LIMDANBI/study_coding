import sys
while True:
    stack = []
    flag = True
    str_line = sys.stdin.readline().rstrip()
    if str_line == ".":
        break
    else:
        for i in str_line:
            if i=='(' or i=='[':
                stack.append(i)
            elif i==')':
                if len(stack)==0 or  stack[-1]!='(':
                    flag = False
                    break
                else:
                    stack.pop()
            elif i==']':
                if len(stack)==0 or stack[-1]!='[':
                    flag = False
                    break
                else:
                    stack.pop()
        if len(stack)==0 and flag:
            print("yes")
        else:
            print("no")